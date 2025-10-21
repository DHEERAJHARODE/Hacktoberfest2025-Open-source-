#Quick sort in python
def quicksort(arr):
    if len(arr)<=1:
        return arr
    pivot = arr[len(arr) // 2]
    left=[x for x in arr if x < pivot]
    middle=[x for x in arr if x=pivot]
    right=[x for x in arr if x>pivot]
    return quicksort(left)+middle+quicksort(right)


#example
arr=[2,5,1,0,6,-1,2]
sorted_arr = quicksort(arr)
print("Sorted arr is",sorted_arr)