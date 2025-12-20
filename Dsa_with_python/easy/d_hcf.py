# finding hcf using division method for positive number

# check the least of  two number 
# difine a variable for quotient 
#  define a varaible for remainder
#  check when the remainer is zero
# return the quotient

def find_gcd(n1:int,n2:int)->int:
    divisor=0
    dividend=0
    if n1 ==0 or n2 ==0 :
        return "number can't divided by zero"
    if n1<n2:
        divisor=n1
        dividend=n2
    else:
        divisor=n2
        dividend=n1
    rem=1
    quo=0
    while rem !=0:
        rem=dividend%divisor
        print('rem: ', rem)
        if rem ==0 :
            break
        dividend=divisor
        print('dividend: ', dividend)
        divisor=rem
    return divisor
# print('check_hcf(2,8): ', check_hcf(13,14))
# print('check_hcf(2,8): ', check_hcf(13,0))