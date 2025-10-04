class ArmstrongUtility:

    @staticmethod
    def is_armstrong(number):
        num_str = str(number)
        power = len(num_str)
        total = sum(int(digit) ** power for digit in num_str)
        return total == number

    @staticmethod
    def find_in_range(start, end):
        armstrong_numbers = []
        for num in range(start, end + 1):
            if ArmstrongUtility.is_armstrong(num):
                armstrong_numbers.append(num)
        return armstrong_numbers


# ---- Single Number Check ----
num = int(input("Enter a number: "))
if ArmstrongUtility.is_armstrong(num):
    print(f"{num} is an Armstrong number")
else:
    print(f"{num} is not an Armstrong number")

# ---- Range Check ----
start = int(input("Enter start of range: "))
end = int(input("Enter end of range: "))
print("Armstrong numbers in range:", ArmstrongUtility.find_in_range(start, end))
