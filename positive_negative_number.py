"""
Make a list. Find 
how many positive and negative numbers are there. 
"""
a = [88, 89, 33, -44, 46, -656, 564, 775, -66, 57]
positive = 0
negative = 0
for i in range(0, len(a)):
    if a[i] >= 0:
        positive += 1

    else:
        negative += 1
print("The length of Positive number is", positive)
print("The length of negative number is", negative)
