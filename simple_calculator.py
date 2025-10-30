"""Enhanced Simple Calculator

Features:
- Safe expression evaluation using Python's AST (no exec/eval of arbitrary code)
- Supports +, -, *, /, %, **, // and unary +/-, parentheses, integers and floats
- Extended math functions: sqrt, sin, cos, tan, log, log10, exp, abs, ceil, floor, round, degrees, radians, etc.
- Mathematical constants: pi, e, tau, inf
- Enhanced REPL with calculation history and help commands
- Smart number formatting (integers, floats, scientific notation)
- Command-line: --expr "pi*2" for one-shot evaluation
- Interactive REPL when no --expr provided with history support
- --test runs comprehensive test suite

Usage examples:
    python simple_calculator.py --expr "sin(pi/2) + cos(0)"
    python simple_calculator.py --expr "sqrt(abs(-16)) * pi"
    python simple_calculator.py  # Interactive mode with history
    python simple_calculator.py --test
    
REPL Commands:
    help     - Show available functions and operators
    history  - Display calculation history
    clear    - Clear calculation history
    quit/exit - Leave calculator
"""
from __future__ import annotations

import ast
import argparse
import math
import sys
from typing import Any


class EvalError(Exception):
    pass


ALLOWED_BINARY_OPS = {
    ast.Add: lambda a, b: a + b,
    ast.Sub: lambda a, b: a - b,
    ast.Mult: lambda a, b: a * b,
    ast.Div: lambda a, b: a / b,
    ast.Mod: lambda a, b: a % b,
    ast.Pow: lambda a, b: a ** b,
    ast.FloorDiv: lambda a, b: a // b,
}

ALLOWED_UNARY_OPS = {
    ast.UAdd: lambda a: +a,
    ast.USub: lambda a: -a,
}


def safe_eval(node: ast.AST) -> float:
    """Recursively evaluate an AST expression node allowing only safe arithmetic.

    Raises EvalError on disallowed nodes.
    """
    if isinstance(node, ast.Expression):
        return safe_eval(node.body)

    if isinstance(node, ast.Constant):
        if isinstance(node.value, (int, float)):
            return float(node.value)
        raise EvalError(f"Unsupported constant type: {type(node.value).__name__}")

    if isinstance(node, ast.Num):  # for Python <3.8 compatibility
        return float(node.n)

    if isinstance(node, ast.Name):
        # Support mathematical constants
        constants = {
            "pi": math.pi,
            "e": math.e,
            "tau": math.tau if hasattr(math, 'tau') else 2 * math.pi,
            "inf": math.inf,
        }
        if node.id in constants:
            return constants[node.id]
        raise EvalError(f"Undefined variable: {node.id}")

    if isinstance(node, ast.BinOp):
        left = safe_eval(node.left)
        right = safe_eval(node.right)
        op_type = type(node.op)
        func = ALLOWED_BINARY_OPS.get(op_type)
        if func is None:
            raise EvalError(f"Operator {op_type.__name__} not allowed")
        try:
            return func(left, right)
        except Exception as e:
            raise EvalError(f"Error evaluating binary op: {e}") from e

    if isinstance(node, ast.UnaryOp):
        operand = safe_eval(node.operand)
        op_type = type(node.op)
        func = ALLOWED_UNARY_OPS.get(op_type)
        if func is None:
            raise EvalError(f"Unary operator {op_type.__name__} not allowed")
        return func(operand)

    if isinstance(node, ast.Call):
        # Allow expanded set of math functions
        allowed_functions = {
            "sqrt", "sin", "cos", "tan", "log", "log10", "exp", 
            "abs", "ceil", "floor", "round", "degrees", "radians",
            "asin", "acos", "atan", "sinh", "cosh", "tanh"
        }
        if isinstance(node.func, ast.Name) and node.func.id in allowed_functions:
            func_name = node.func.id
            args = [safe_eval(arg) for arg in node.args]
            try:
                if func_name == "round" and len(args) == 1:
                    # Use Python's built-in round for single argument
                    return float(round(args[0]))
                elif func_name == "abs":
                    # Use Python's built-in abs
                    return float(abs(args[0]))
                else:
                    f = getattr(math, func_name)
                    return float(f(*args))
            except (AttributeError, ValueError, TypeError) as e:
                raise EvalError(f"Error calling {func_name}: {e}")
        raise EvalError(f"Function calls are not allowed except math functions: {', '.join(sorted(allowed_functions))}")

    if isinstance(node, ast.Expr):
        return safe_eval(node.value)

    if isinstance(node, ast.Paren):  # rare / not present in AST, kept for safety
        return safe_eval(node.value)

    raise EvalError(f"Unsupported AST node: {node.__class__.__name__}")


def evaluate_expression(expr: str) -> float:
    """Parse and safely evaluate a single arithmetic expression string."""
    try:
        parsed = ast.parse(expr, mode="eval")
    except SyntaxError as e:
        raise EvalError(f"Syntax error: {e.msg}") from e
    return safe_eval(parsed)


def format_result(result: float) -> str:
    """Format calculation result for display."""
    if abs(result) > 1e15 or (abs(result) < 1e-4 and result != 0):
        # Use scientific notation for very large or very small numbers
        return f"{result:.6e}"
    elif abs(result - int(result)) < 1e-12:
        # Display as integer when possible
        return str(int(result))
    else:
        # Display as float with reasonable precision
        return f"{result:.10g}"


def repl() -> None:
    print("Enhanced Calculator REPL — Enhanced with more functions, constants, and history!")
    print("Type 'help' for commands, 'quit' or 'exit' to leave.")
    
    history = []  # Store calculation history
    
    while True:
        try:
            s = input("calc> ").strip()
        except (EOFError, KeyboardInterrupt):
            print()
            break
        if not s:
            continue
        if s.lower() in ("quit", "exit"):
            break
        if s.lower() in ("help", "h"):
            print("\n=== Calculator Help ===")
            print("Operators: + - * / % ** // (floor division)")
            print("Functions: sqrt, sin, cos, tan, log, log10, exp, abs, ceil, floor, round")
            print("           degrees, radians, asin, acos, atan, sinh, cosh, tanh")
            print("Constants: pi, e, tau, inf")
            print("Commands: 'history' - show calculation history")
            print("          'clear' - clear history")
            print("Examples: pi * 2, sqrt(16), sin(pi/2), abs(-5)")
            print("======================\n")
            continue
        if s.lower() == "history":
            if history:
                print("\n=== Calculation History ===")
                for i, (expr, res) in enumerate(history[-10:], 1):  # Show last 10
                    print(f"{i:2d}. {expr} = {res}")
                print("===========================\n")
            else:
                print("No calculation history yet.")
            continue
        if s.lower() == "clear":
            history.clear()
            print("History cleared.")
            continue
        
        try:
            result = evaluate_expression(s)
        except EvalError as e:
            print(f"Error: {e}")
        except Exception as e:
            print(f"Unexpected error: {e}")
        else:
            formatted_result = format_result(result)
            print(formatted_result)
            # Add to history
            history.append((s, formatted_result))


def run_tests() -> bool:
    tests = {
        # Basic arithmetic
        "1+2*3": 7,
        "(1+2)*3": 9,
        "2**3**1": 8,  # 2**(3**1) -> 2**3
        "4/2": 2,
        "5%2": 1,
        "-3 + 7": 4,
        "9//2": 4,  # floor division
        
        # Basic math functions
        "sqrt(16)": 4,
        "sin(0)": 0,
        "abs(-5)": 5,
        "ceil(3.2)": 4,
        "floor(3.8)": 3,
        "round(3.7)": 4,
        
        # Constants
        "pi/pi": 1,
        "e/e": 1,
        
        # Advanced functions
        "log10(100)": 2,
        "exp(0)": 1,
        "degrees(pi)": 180,
    }
    ok = True
    for expr, expected in tests.items():
        try:
            got = evaluate_expression(expr)
        except EvalError as e:
            print(f"FAIL: {expr} -> raised EvalError: {e}")
            ok = False
            continue
        # compare numeric with tolerance
        if abs(got - expected) > 1e-9:
            print(f"FAIL: {expr} = {got} (expected {expected})")
            ok = False
        else:
            print(f"OK:   {expr} = {got}")
    return ok


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Simple safe calculator")
    parser.add_argument("--expr", "-e", help="evaluate expression and exit", type=str)
    parser.add_argument("--test", help="run internal tests", action="store_true")
    args = parser.parse_args(argv)

    if args.test:
        success = run_tests()
        print("All tests passed." if success else "Some tests failed.")
        return 0 if success else 2

    if args.expr:
        try:
            result = evaluate_expression(args.expr)
        except EvalError as e:
            print(f"Error: {e}")
            return 1
        print(format_result(result))
        return 0

    repl()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
