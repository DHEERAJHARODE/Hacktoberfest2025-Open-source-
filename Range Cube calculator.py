print("-----------------------------START--------------------------")
print("1: Both numbers are positive")
print("2: Both numbers are negative")
print("3: One is positive and one is negative")
CH=int(input("Enter choice between 1 and 3:"))
if CH==1:
    N=int(input("Enter first number:"))
    M=int(input("Enter second number:"))
    i=0
    for i in range(N,M):
        n=i*i*i
        i+=1
        print("The cube of number", i-1," is:",n)

if CH==2:
    N=int(input("Enter first number:"))
    M=int(input("Enter second number:"))
    i=0
    for i in range(-M,-N):
        n=i*i*i
        i-=1
        print("The cube of number", i+1," is:",n)

if CH==3:
    N=int(input("Enter first number:"))
    M=int(input("Enter second number:"))
    i=0
    for i in range(-N,M):
        n=i*i*i
        i+=1
        print("The cube of number", i-1," is:",n)


print("---------------------------END-------------------------")
