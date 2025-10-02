class Solution {
  public String reverseWords(String s) {
    String[] words = s.trim().split("\\s+");
    String output = "";

    for (int i = words.length - 1; i > 0; i--) {
      output += words[i] + " ";
    }
    return output + words[0];
  }
}

class reverseWords {
  public static void main(String[] args) {
    Solution sol = new Solution();
    String s = "  hello world  ";
    System.out.println(sol.reverseWords(s)); // Output: "world hello"
  }
}