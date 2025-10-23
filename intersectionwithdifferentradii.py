x1, y1, r1 = map(int, input().split())
x2, y2, r2 = map(int, input().split())

dx = x1 - x2
dy = y1 - y2
D2 = dx*dx + dy*dy
S = r1 + r2
T = abs(r1 - r2)

print("YES" if T*T <= D2 <= S*S else "NO")
