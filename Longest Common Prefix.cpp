#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }
    
    std::string prefix = strs[0]; // Take the first string as the initial prefix
    
    for (int i = 1; i < strs.size(); ++i) {
        int j = 0;
        while (j < prefix.length() && j < strs[i].length() && prefix[j] == strs[i][j]) {
            ++j;
        }
        prefix = prefix.substr(0, j); // Update prefix with the common characters
    }
    
    return prefix;
}

int main() {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = longestCommonPrefix(strs);
    std::cout << "Longest Common Prefix: " << result << std::endl;
    return 0;
}
