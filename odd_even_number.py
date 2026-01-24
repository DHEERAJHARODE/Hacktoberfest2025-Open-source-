# Function to check if a number is odd or even
def check_odd_even(number):
    if number % 2 == 0:
        return f"{number} is even."
    else:
        return f"{number} is odd."

# Example usage
num = int(input("Enter a number: "))
result = check_odd_even(num)
print(result)
