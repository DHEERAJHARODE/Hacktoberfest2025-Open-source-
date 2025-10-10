import java.util.*;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int n = basket1.length;
        Map<Integer, Integer> balance = new TreeMap<>();
        int minVal = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int a = basket1[i], b = basket2[i];
            balance.put(a, balance.getOrDefault(a, 0) + 1);
            balance.put(b, balance.getOrDefault(b, 0) - 1);
            minVal = Math.min(minVal, Math.min(a, b));
        }

        List<Integer> transfers = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : balance.entrySet()) {
            int cost = entry.getKey(), bal = entry.getValue();
            if (bal % 2 != 0) {
                return -1;  // Balancing impossible
            }
            for (int count = Math.abs(bal) / 2; count > 0; count--) {
                transfers.add(cost);
            }
        }

        Collections.sort(transfers);
        long totalCost = 0;
        int m = transfers.size();
        for (int i = 0; i < m / 2; i++) {
            totalCost += Math.min(transfers.get(i), 2L * minVal);
        }
        return totalCost;
    }
}
