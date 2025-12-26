#include <bits/stdc++.h>
using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(vector<string>& strs) {
    // If the vector is empty, return "-1"
    if (strs.empty()) return "-1";

    // Sort the vector of strings
    sort(strs.begin(), strs.end());

    // Compare the first and last strings
    // in the sorted list
    string first = strs.front();
    string last = strs.back();
    int minLength = min(first.size(), last.size());

    int i = 0;
    // Find the common prefix between the first
    // and last strings
    while (i < minLength && first[i] == last[i]) {
        i++;
    }

    // Check if there's no common prefix
    if (i == 0) return "-1";

    // Return the common prefix
    return first.substr(0, i);
}

int main() {
    vector<string> strs = {"geeksforgeeks", "geeks",
                           "geek", "geezer"};
    cout << "The longest common prefix is: " <<
      longestCommonPrefix(strs) << endl;

    return 0;
}
