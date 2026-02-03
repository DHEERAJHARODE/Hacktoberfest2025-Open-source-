//Tribonacci solution for Bottom-Up approach
#include <iostream>
#include <vector>

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    
    int result = tribonacci(n);
    std::cout << "The Tribonacci number at position " << n << " is: " << result << std::endl;
    
    return 0;
}

//Tribonacci solution for Top-down approach
#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int tribonacci(int n) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    if (n == 0) {
        memo[n] = 0;
    } else if (n == 1 || n == 2) {
        memo[n] = 1;
    } else {
        memo[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = tribonacci(n);
    std::cout << "The Tribonacci number at position " << n << " is: " << result << std::endl;

    return 0;
}
