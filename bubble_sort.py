import random

def bubble_sort(arr, descending=False):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if (not descending and arr[j] > arr[j + 1]) or (descending and arr[j] < arr[j + 1]):
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


if __name__ == "__main__":
    nums = [random.randint(1, 100) for _ in range(10)]
    print("Original array:", nums)

    sorted_asc = bubble_sort(nums.copy(), descending=False)
    print("Sorted ascending:", sorted_asc)

    sorted_desc = bubble_sort(nums.copy(), descending=True)
    print("Sorted descending:", sorted_desc)
