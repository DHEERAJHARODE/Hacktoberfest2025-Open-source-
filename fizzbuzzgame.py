def fizz_buzz(n: int):
    """
    Prints numbers from 1 to n with the following rules:
    - Multiples of 3 -> "Fizz"
    - Multiples of 5 -> "Buzz"
    - Multiples of both 3 and 5 -> "FizzBuzz"
    """
    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz")
        elif i % 3 == 0:
            print("Fizz")
        elif i % 5 == 0:
            print("Buzz")
        else:
            print(i)

if __name__ == "__main__":
    fizz_buzz(20)
