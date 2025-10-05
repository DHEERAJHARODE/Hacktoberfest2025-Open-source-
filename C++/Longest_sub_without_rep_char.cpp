#include <bits/stdc++.h>
using namespace std;

/*
  Problem: Longest Substring Without Repeating Characters
  Approach: Sliding Window + Hash Map
  Time Complexity: O(n)
  Space Complexity: O(256) ≈ O(1)
*/

int lengthOfLongestSubstring(string s) {
    vector<int> lastIndex(256, -1); // store last index of each character
    int maxLen = 0;
    int start = 0; // left pointer of window

    for (int end = 0; end < s.length(); end++) {
        // If character is repeated, move start to right of last occurrence
        if (lastIndex[s[end]] >= start)
            start = lastIndex[s[end]] + 1;

        lastIndex[s[end]] = end; // update last index
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "pwwkew";
    cout << "Length of longest substring without repeating characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
