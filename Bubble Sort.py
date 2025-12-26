def bubblesort(elements):
	swapped = False
	for n in range(len(elements)-1, 0, -1):
		for i in range(n):
			if elements[i] > elements[i + 1]:
				swapped = True
				elements[i], elements[i + 1] = elements[i + 1], elements[i]	
		if not swapped:
			return

elements = [139, 122, 98, 825, 72, 1340, 2, 18]

print("Unsorted list is,")
print(elements)
bubblesort(elements)
print("Sorted Array is, ")
print(elements)
