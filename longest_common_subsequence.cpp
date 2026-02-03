#include<bits/stdc++.h>  
using namespace std; 
#include <iostream>
#include <vector>
#include <string>


// Function to find the common prefix of two strings
std::string commonPrefix(const std::string& str1, const std::string& str2) {
    std::string result;
    int len1 = str1.length();
    int len2 = str2.length();
    int i = 0, j = 0;

    while (i < len1 && j < len2) {
        if (str1[i] != str2[j]) {
            break;
        }
        result += str1[i];
        i++;
        j++;
    }

    return result;
}

// Function to find the longest common prefix among an array of strings
std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    std::string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        prefix = commonPrefix(prefix, strs[i]);
        if (prefix.empty()) {
            break;
        }
    }

    return prefix;
}

int main() {
    std::vector<std::string> strings = {"flower", "flourish", "flour", "flop"};
    std::string result = longestCommonPrefix(strings);

    if (result.empty()) {
        std::cout << "No common prefix found." << std::endl;
    } else {
        std::cout << "Longest common prefix: " << result << std::endl;
    }

    return 0;
}

//find length of longest common subsequence
int lcs(string a,string b,int m,int n)  {   

    int dp[m + 1][n + 1];   
    for (int i = 0; i <= m; i++) {  
        for (int j = 0; j <= n; j++)  {  
            //dp[i][j] contains lcs of string a(0..i) and b(0..j)
            if (i == 0 || j == 0)  
                dp[i][j] = 0;  
            else if (a[i - 1] == b[j - 1])  
                dp[i][j] = dp[i - 1][j - 1] + 1;  
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  
        }  
    }  
    return dp[m][n];  
}


int main() {  
    //desired strings are taken
    string a = "longest";
    string b = "longsequence";

    int m = a.size();  
    int n = b.size();  
    
    //Print the length of longest common subsequence  
    cout << "The length of Longest Common Subsequence is " << lcs(a,b,m,n);  
      
    return 0;  
}  