def fibonacci(n):
    dp = [0] * (n + 1)
    dp[0] = 0
    dp[1] = 1
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]

# Test the function
n = 10
result = fibonacci(n)
print("The {}-th Fibonacci number is: {}".format(n, result))
