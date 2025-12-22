from math import sqrt
t = int(input())

for i in range(t):
    n = int(input())
    a, b, c = map(int, input().split())
    x = []
    y = []
    for j in range(n):
        a1, b1 = map(int, input().split())
        x += [a1]
        y += [b1]
    l = -15000
    r = 15000
    while (r - l) > 0.00001:
        m1 = (2 * l + r) / 3
        m2 = (-(a * m1) - c) / b
        m3 = (l + 2 * r) / 3
        m4 = (-(a * m3) - c) / b
        d1 = 0
        for k in range(n):
            d1 += sqrt((m1 - x[k]) ** 2 + (m2 - y[k]) ** 2)
        d2 = 0
        for z in range(n):
            d2 += sqrt((m3 - x[z]) ** 2 + (m4 - y[z]) ** 2)
        if d1 <= d2: 
            r = m3
        else: 
            l = m1
    print(min(d1,d2))
