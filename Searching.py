def linear_search(num, array):
    for i in range(len(array)):
        if num == i:
            print(f"We found ${num}")
            return
    print("No such number.")

def binary_search(num, array):
    low = 0; high = len(array) - 1
    while low <= high:
        mid = (low + high) // 2
        if array[mid] < num:
            low = mid + 1
        elif array[mid] > num:
            high = mid - 1
        else:
            print(f"{num} is at position {mid}")
            return
    print("No such number")

array = [n + 1 for n in range(10)]

num = int(input("Enter a number to search: "))
binary_search(num, array)
