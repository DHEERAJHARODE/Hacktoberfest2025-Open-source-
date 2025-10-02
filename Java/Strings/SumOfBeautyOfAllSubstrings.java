import java.util.HashMap;

class Solution {
  public int beautySum(String s) {
    int BeautySum = 0;
    for (int i = 0; i < s.length(); i++) {
      HashMap<Character, Integer> map = new HashMap<>();
      for (int j = i; j < s.length(); j++) {
        char CurrChar = s.charAt(j);
        if (map.containsKey(CurrChar)) {
          map.put(CurrChar, map.get(CurrChar) + 1);
        } else {
          map.put(CurrChar, 1);
        }

        BeautySum += calculateBeauty(map);
      }
    }

    return BeautySum;
  }

  private int calculateBeauty(HashMap<Character, Integer> map) {
    int maxFreq = Integer.MIN_VALUE;
    int minFreq = Integer.MAX_VALUE;

    for (int freq : map.values()) {
      maxFreq = Math.max(maxFreq, freq);
      minFreq = Math.min(minFreq, freq);
    }

    return maxFreq - minFreq;
  }
}

public class SumOfBeautyOfAllSubstrings {
  public static void main(String[] args) {
    Solution solution = new Solution();
    String s = "aabcb";
    System.out.println(solution.beautySum(s));
  }
}