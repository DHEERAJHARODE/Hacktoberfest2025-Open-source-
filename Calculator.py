# Simple Calculator in Python

# This function adds two numbers
def add(x, y):
    return x + y

# This function subtracts two numbers
def subtract(x, y):
    return x - y

# This function multiplies two numbers
def multiply(x, y):
    return x * y

# This function divides two numbers
def divide(x, y):
    if y == 0:
        return "Error! Division by zero."
    else:
        return x / y


# Main program starts here
print("Simple Calculator")
print("-----------------")
print("Select operation:")
print("1. Add")
print("2. Subtract")
print("3. Multiply")
print("4. Divide")

# Take input from the user
choice = input("Enter choice (1/2/3/4): ")

# Get numbers from the user
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

# Perform calculation based on user's choice
if choice == '1':
    print(f"The result is: {add(num1, num2)}")

elif choice == '2':
    print(f"The result is: {subtract(num1, num2)}")

elif choice == '3':
    print(f"The result is: {multiply(num1, num2)}")

elif choice == '4':
    print(f"The result is: {divide(num1, num2)}")

else:
    print("Invalid input! Please choose a number between 1 and 4.")
