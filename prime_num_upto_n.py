#Write a Python program for printing prime numbers up to N. (N>100).
n = int(input("Enter the limit : "))

for i in range(1,n+1):
    for j in range(2,i):
        if(i%j)==0:
            break
    else:
        print(i,end=" ")
