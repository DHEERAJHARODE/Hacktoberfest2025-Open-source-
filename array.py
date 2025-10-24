my_array = [10, 20, 30, 40, 50]
print(f"Original Array: {my_array}")

first_element = my_array[0]
third_element = my_array[2]
last_element = my_array[-1]
print(f"First element (index 0): {first_element}")
print(f"Third element (index 2): {third_element}")
print(f"Last element (index -1): {last_element}")

my_array[1] = 25  
print(f"Array after modification: {my_array}")

my_array.append(60) 
my_array.insert(0, 5) 
print(f"Array after adding elements: {my_array}")

my_array.pop()  
my_array.remove(30)  
print(f"Array after removing elements: {my_array}")

print("Iterating through the array (printing double the value of each item):")
for item in my_array:
    print(item * 2)
