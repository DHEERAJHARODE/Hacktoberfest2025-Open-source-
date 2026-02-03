import math

def function(x,b,c):
    return ((x**2) + (b*x) + c)/math.sin(x)

def ternary_search(l , r, precision, b, c):
    count = 0
    while r - l > precision:
        partition = (r - l) / 3

        m1 = l + partition
        m2 = r - partition
        
        fm1 = function(m1, b, c)
        fm2 = function(m2, b, c)
        if fm1 > fm2:
            l = m1
        elif fm1 < fm2:
            r = m2
        else:
            l = m1
            r = m2
        count += 1
    return l

cant = int(input())

for i in range(cant):
    b,c = map(float, input().split())

    print(function(ternary_search(0,math.pi/2,10**-6,b,c),b,c))
