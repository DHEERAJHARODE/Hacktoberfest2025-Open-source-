
def uniquePathsWithObstacles(A,r,c):

    n = A

    m = A
    if n == 1 and m == 1 and  i not in r and j not in c:

        return 1

    if n == 1 and m == 1 and i in r and j in c:

        return 0

    dp = [[-1 for j in range(m)] for i in range(n)]
 

    def path(dp, A,r, c, i, j):

        if i < n and j < m and i in r and j in c:

            return 0

        if i == n - 1 and j == m - 1:

            return 1

        if i >= n or j >= m:

            return 0

        if dp[i][j] != -1:

            return dp[i][j]

        left = path(dp, A,r,c, i + 1, j)

        right = path(dp, A,r,c, i, j + 1)

        dp[i][j] = left + right

        return dp[i][j]

    path(dp, A,r,c, 0, 0)

    if dp[0][0] == -1:

        return 0

    return dp[0][0]
 

A=5
B=0
m=(A-1)//2
r=[]
c=[]
for i in range(m-B,m+B+1):
   for j in range(m-B,m+B+1):
      r.append(i)
      c.append(j)

print(uniquePathsWithObstacles(A,r,c))