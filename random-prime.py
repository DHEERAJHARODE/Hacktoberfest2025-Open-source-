import random

# Function to check if a number is prime
def is_prime(num):
    if num < 2:
        return False  # Any number less than 2 is not prime
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False  # If divisible by any number other than 1 and itself, it's not prime
    return True

# Function to generate random prime numbers within a range
def generate_random_prime(start, end, count):
    primes = []
    while len(primes) < count:  # Keep generating until we have the desired number of primes
        candidate = random.randint(start, end)  # Generate a random number within the range
        if is_prime(candidate):  # Check if the generated number is prime
            primes.append(candidate)  # Add to list if prime
    return primes

# Generate 5 random prime numbers between 10 and 100
random_primes = generate_random_prime(10, 100, 5)

# Print the prime numbers
print("These numbers are prime numbers:")
for prime in random_primes:
    print(prime)
