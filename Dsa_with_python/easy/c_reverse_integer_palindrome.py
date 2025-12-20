def isPalindrome(x: int) -> bool:
    if x<0  or x%10 == 0:
        return False
    else:
        new_x=x
        digit_list=[]
        while new_x:
            digit_list.append(new_x%10)
            new_x=new_x//10
        rev=0
        for i in range((len(digit_list))):
            rev+=digit_list[len(digit_list)-1-i]*pow(10,i)
        if(rev == x):
            return True
        else:
            return False
            
print(isPalindrome(121))
print(isPalindrome(-121))
print(isPalindrome(1200))
print(isPalindrome(1021))
print(isPalindrome(1001))