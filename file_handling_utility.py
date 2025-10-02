"""
A collection of practical file handling utilities designed to avoid common
pitfalls like data corruption, race conditions, and encoding issues.

These functions prioritize safety and reliability over raw speed. They are
intended for use in scripts or applications where data integrity matters.
"""

import os
import sys
import shutil
import tempfile
import logging
import time
from contextlib import contextmanager

# Set up a basic logger that outputs to stderr
logger = logging.getLogger(__name__)
logger.setLevel(logging.WARNING)
if not logger.handlers:
    handler = logging.StreamHandler()
    handler.setFormatter(logging.Formatter('[%(levelname)s] %(message)s'))
    logger.addHandler(handler)


def safe_write(filepath, content, encoding='utf-8', make_dirs=True):
    """
    Write content to a file safely.

    Writes to a temporary file in the same directory, then atomically replaces
    the target. This ensures the original file is never left in a partial or
    corrupted state if the process is killed mid-write.

    If the parent directory doesn't exist and make_dirs is True, it will be created.

    Args:
        filepath (str): Path to the destination file.
        content (str): Data to write.
        encoding (str): Text encoding to use (default: utf-8).
        make_dirs (bool): Create parent directories if missing.

    Raises:
        OSError: If file system operations fail.
        ValueError: If content is not a string.
    """
    if not isinstance(content, str):
        raise ValueError("Content must be a string")

    dir_path = os.path.dirname(filepath)
    if dir_path and make_dirs:
        os.makedirs(dir_path, exist_ok=True)

    # Use the same directory for temp file to ensure atomic rename works
    temp_dir = dir_path if dir_path else '.'

    temp_path = None
    try:
        with tempfile.NamedTemporaryFile(
            mode='w',
            encoding=encoding,
            dir=temp_dir,
            delete=False
        ) as tmp:
            tmp.write(content)
            temp_path = tmp.name

        # Atomic replace on Unix; on Windows, replace will overwrite if possible
        os.replace(temp_path, filepath)
        logger.debug(f"Successfully wrote {filepath} safely")
    except Exception:
        # Clean up temp file on failure
        if temp_path and os.path.exists(temp_path):
            try:
                os.unlink(temp_path)
            except OSError:
                pass  # Best effort
        raise


def read_file(filepath, encoding='utf-8', fallback_encodings=None):
    """
    Read a text file with fallback encodings.

    Attempts to read the file using the primary encoding. If that fails due to
    a UnicodeDecodeError, it tries a list of fallback encodings (e.g., 'latin1',
    'cp1252').

    Args:
        filepath (str): Path to file.
        encoding (str): Primary encoding to try.
        fallback_encodings (list): Optional list of fallback encodings.

    Returns:
        str: File contents.

    Raises:
        FileNotFoundError, PermissionError, etc., as appropriate.
    """
    if fallback_encodings is None:
        fallback_encodings = ['latin1', 'cp1252', 'iso-8859-1']

    encodings_to_try = [encoding] + [e for e in fallback_encodings if e != encoding]

    for enc in encodings_to_try:
        try:
            with open(filepath, 'r', encoding=enc) as f:
                return f.read()
        except UnicodeDecodeError:
            continue
        except Exception:
            # Re-raise non-encoding errors immediately
            raise

    # If all encodings failed
    raise UnicodeDecodeError(
        "unknown",
        b"",
        0,
        0,
        f"Could not decode {filepath} with any of: {encodings_to_try}"
    )


@contextmanager
def file_lock(filepath, timeout=10, poll_interval=0.1):
    """
    Context manager that provides a simple file-based lock.

    Creates a '.lock' file alongside the target. If the lock file exists,
    waits up to `timeout` seconds before giving up.

    Not suitable for high-concurrency or cross-platform production use,
    but sufficient for simple scripting scenarios.

    Usage:
        with file_lock("data.txt"):
            safe_write("data.txt", new_content)

    Args:
        filepath (str): Path to the file you want to protect.
        timeout (float): Max time to wait for the lock (seconds).
        poll_interval (float): How often to check for lock release.

    Raises:
        TimeoutError: If lock cannot be acquired within timeout.
    """
    lockfile = filepath + '.lock'
    start = time.time()

    while True:
        try:
            # Attempt to create lock file exclusively
            fd = os.open(lockfile, os.O_CREAT | os.O_EXCL | os.O_RDWR)
            os.close(fd)
            break
        except FileExistsError:
            if time.time() - start > timeout:
                raise TimeoutError(f"Could not acquire lock on {filepath} after {timeout}s")
            time.sleep(poll_interval)

    try:
        yield
    finally:
        try:
            os.unlink(lockfile)
        except OSError:
            pass  # Might have been deleted already


def backup_file(filepath, suffix='.bak'):
    """
    Create a backup of a file if it exists.

    The backup is placed in the same directory with the given suffix appended.
    If a backup already exists, it is overwritten.

    Returns:
        str or None: Path to the backup file if created, None if source didn't exist.
    """
    if not os.path.exists(filepath):
        return None

    backup_path = filepath + suffix
    shutil.copy2(filepath, backup_path)  # preserves metadata
    logger.debug(f"Backed up {filepath} to {backup_path}")
    return backup_path


def safe_copy(src, dst, make_dirs=True):
    """
    Copy a file safely, creating parent directories if needed.

    Uses shutil.copy2 for metadata preservation. If dst is a directory,
    the file is copied into it with the same name.

    Args:
        src (str): Source file path.
        dst (str): Destination path (file or directory).
        make_dirs (bool): Create destination parent dirs if missing.

    Returns:
        str: Actual destination path of the copied file.
    """
    if not os.path.isfile(src):
        raise FileNotFoundError(f"Source file not found: {src}")

    dst_path = dst
    if os.path.isdir(dst):
        dst_path = os.path.join(dst, os.path.basename(src))

    if make_dirs:
        os.makedirs(os.path.dirname(dst_path), exist_ok=True)

    shutil.copy2(src, dst_path)
    return dst_path


# ----------------------------
# Command-line interface
# ----------------------------

def _main():
    """Simple CLI for testing or basic usage."""
    if len(sys.argv) < 2:
        print("Usage:")
        print("  python file_utils.py write <file> <content>")
        print("  python file_utils.py read <file>")
        print("  python file_utils.py backup <file>")
        print("  python file_utils.py copy <src> <dst>")
        return

    command = sys.argv[1]

    try:
        if command == "write" and len(sys.argv) == 4:
            safe_write(sys.argv[2], sys.argv[3])
            print(f"Wrote to {sys.argv[2]} safely.")
        elif command == "read" and len(sys.argv) == 3:
            content = read_file(sys.argv[2])
            print(content, end='')
        elif command == "backup" and len(sys.argv) == 3:
            bk = backup_file(sys.argv[2])
            if bk:
                print(f"Backup created: {bk}")
            else:
                print("File not found; no backup made.")
        elif command == "copy" and len(sys.argv) == 4:
            dst = safe_copy(sys.argv[2], sys.argv[3])
            print(f"Copied to {dst}")
        else:
            print("Invalid command or arguments.", file=sys.stderr)
            sys.exit(1)
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    _main()
