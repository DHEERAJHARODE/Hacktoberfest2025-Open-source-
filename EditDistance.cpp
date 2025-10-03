#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string word1 = "horse";
    std::string word2 = "ros";
    std::cout << "Word 1: " << word1 << std::endl;
    std::cout << "Word 2: " << word2 << std::endl;
    std::cout << "Edit Distance: " << minDistance(word1, word2) << std::endl;

    std::cout << "\n";

    std::string word3 = "intention";
    std::string word4 = "execution";
    std::cout << "Word 1: " << word3 << std::endl;
    std::cout << "Word 2: " << word4 << std::endl;
    std::cout << "Edit Distance: " << minDistance(word3, word4) << std::endl;

    return 0;
}
