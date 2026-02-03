try:
    n=int(input('Enter number to reverse :'))
    n=str(n)
    n=n[::-1]
    n=int(n)
    print('reversed number of given number =', n)

except ValueError:
    print('Given input is not a accepted value') 
