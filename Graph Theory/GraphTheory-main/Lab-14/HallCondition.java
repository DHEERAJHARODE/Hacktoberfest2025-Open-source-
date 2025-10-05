import java.util.*;

public class HallCondition {
    
    public static boolean checkHallCondition(String[][] graph, String[] X, String[] Y) {
        int n = X.length;
        boolean hallHolds = true;

        // Iterate over all subsets of X (except empty set)
        // (1 << n) = Math.pow(2 , n)
        for (int mask = 1; mask < (1 << n); mask++) {
            Set<String> neighbors = new HashSet<>();
            List<String> subset = new ArrayList<>();
            int subsetSize = 0;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) { // if xi is in subset
                    subsetSize++;
                    subset.add(X[i]);
                    neighbors.addAll(Arrays.asList(graph[i]));
                }
            }

            // Print subset and its neighbors
            System.out.println("Subset: " + subset + " | Neighbors: " + neighbors);

            if (neighbors.size() < subsetSize) {
                hallHolds = false;
                System.out.println("Hall’s condition fails for subset: " + subset);
            } else {
                System.out.println("Condition holds for this subset");
            }
        }

        return hallHolds;
    }

    public static void main(String[] args) {
        String[] X = {"x1","x2","x3"};
        String[] Y = {"y1","y2","y3"};
        String[][] graph1 = {{"y1","y2"}, {"y1","y3"}, {"y3"}};

        boolean result = checkHallCondition(graph1, X, Y);
        System.out.println("\nFinal Result: Hall’s condition holds? " + result);
    }
}
