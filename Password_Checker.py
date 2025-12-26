import itertools
import string
import time

def crack_password(password, max_length=6):
    characters = string.ascii_letters + string.digits + string.punctuation
    start_time = time.time()
    
    for length in range(1, max_length + 1):
        for guess in itertools.product(characters, repeat=length):
            guess = ''.join(guess)
            if guess == password:
                end_time = time.time()
                elapsed_time = end_time - start_time
                return elapsed_time

    return None

password = "your_password_here"
estimated_time = crack_password(password)

if estimated_time:
    print(f"Estimated time to crack the password: {estimated_time:.2f} seconds")
else:
    print("Password not cracked within the specified length.")
