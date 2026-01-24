# Function to check if a number is odd or even
def check_odd_even_with_validation():
    try:
        number = int(input("Enter an integer: "))  # Prompt user for input
        if number % 2 == 0:
            print(f"{number} is even.")
        else:
            print(f"{number} is odd.")
    except ValueError:
        print("Invalid input! Please enter a valid integer.")

# Example usage
check_odd_even_with_validation()
