"@author: Suprabhat Chowhan"
#Let's create a program to provide choices for the calculation of area or the perimeter of the circle.
Radius= float(input("Enter the radius of the circle:"))
print("1. Calculate the Perimeter")
print("2. Calculate the Area")
choices=int(input("Provide your choice (1 or 2) :"))
if choices==1:
    perimeter= 2*22/7*Radius
    print("The perimeter is",perimeter)
else:
    area=3.14*Radius*Radius
    print("The area of the circle is:",area)
    