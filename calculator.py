#!/usr/bin/env python3
"""
Simple Calculator Program

This program provides basic arithmetic operations including:
- Addition
- Subtraction  
- Multiplication
- Division

The calculator runs in a loop until the user chooses to exit.
"""

def add(x, y):
    """Add two numbers and return the result."""
    return x + y

def subtract(x, y):
    """Subtract y from x and return the result."""
    return x - y

def multiply(x, y):
    """Multiply two numbers and return the result."""
    return x * y

def divide(x, y):
    """Divide x by y and return the result.
    
    Raises:
        ZeroDivisionError: If y is zero
    """
    if y == 0:
        raise ZeroDivisionError("Cannot divide by zero!")
    return x / y

def get_number_input(prompt):
    """Safely get a numeric input from user with error handling."""
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            print("Invalid input! Please enter a valid number.")

def display_menu():
    """Display the calculator menu options."""
    print("\n" + "="*30)
    print("        SIMPLE CALCULATOR")
    print("="*30)
    print("Select operation:")
    print("1. Add")
    print("2. Subtract") 
    print("3. Multiply")
    print("4. Divide")
    print("5. Exit")
    print("="*30)

def main():
    """Main calculator function that handles the program flow."""
    operations = {
        '1': {'name': 'Add', 'symbol': '+', 'function': add},
        '2': {'name': 'Subtract', 'symbol': '-', 'function': subtract},
        '3': {'name': 'Multiply', 'symbol': '*', 'function': multiply},
        '4': {'name': 'Divide', 'symbol': '/', 'function': divide}
    }
    
    while True:
        display_menu()
        choice = input("Enter your choice (1-5): ").strip()
        
        if choice == '5':
            print("Thank you for using the calculator. Goodbye!")
            break
            
        if choice in operations:
            try:
                # Get numbers from user
                num1 = get_number_input("Enter first number: ")
                num2 = get_number_input("Enter second number: ")
                
                operation = operations[choice]
                result = operation['function'](num1, num2)
                
                # Display result
                print(f"\n{num1} {operation['symbol']} {num2} = {result}")
                
            except ZeroDivisionError as e:
                print(f"\nError: {e}")
            except Exception as e:
                print(f"\nAn unexpected error occurred: {e}")
        else:
            print("Invalid choice! Please select 1-5.")
        
        # Ask if user wants to continue (only if not exiting)
        if choice != '5':
            continue_calc = input("\nWould you like to perform another calculation? (yes/no): ").strip().lower()
            if continue_calc not in ['yes', 'y', '']:
                print("Thank you for using the calculator. Goodbye!")
                break

if __name__ == "__main__":
    main()
