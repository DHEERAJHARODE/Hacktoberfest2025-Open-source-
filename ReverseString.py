# Reverse a string in Python

def reverse_string(s):
    return s[::-1]

if __name__ == "__main__":
    user_input = input("Enter a string to reverse: ")
    reversed_string = reverse_string(user_input)
    print("Reversed String:", reversed_string)
