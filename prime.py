import math

def is_prime(number):
    """
    Checks if a given number is a prime number.

    A prime number is a natural number greater than 1 that has no positive
    divisors other than 1 and itself.
    """
    if number <= 1:
        return False  # Numbers less than or equal to 1 are not prime

    # Check for divisibility from 2 up to the square root of the number.
    # We only need to check up to the square root because if a number 'n' has a
    # divisor 'd' greater than its square root, then it must also have a
    # divisor 'n/d' which is less than its square root.
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False  # If divisible, it's not prime

    return True  # If no divisors found, it's prime

# Example usage:
num = int(input("Enter a number: "))

if is_prime(num):
    print(f"{num} is a prime number.")
else:
    print(f"{num} is not a prime number.")
