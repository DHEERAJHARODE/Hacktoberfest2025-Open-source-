def palindrome(num):
    '''Function to find out the palindrome of a number'''
    temp = num
    rev = 0
    while temp > 0:
        dig = temp % 10
        rev = rev * 10 + dig
        temp = temp // 10
    if num == rev:
        print("The number is a palindrome!")
    else:
        print("The number isn't a palindrome!")
