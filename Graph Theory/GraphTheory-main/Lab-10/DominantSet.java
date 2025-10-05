import java.util.*;

public class DominantSet {
    public static void main(String[] args) {
        int N = 4;
        int[][] edges = {{1, 2}, {1, 3}, {3, 4}, {2, 4}};
        
        List<Set<Integer>> allDominantSets = getAllDominantSets(N, edges);
        System.out.println("All Dominant Sets:");
        for (Set<Integer> set : allDominantSets) {
            System.out.println(set);
        }
    }

    // Get all Dominant Sets
    static List<Set<Integer>> getAllDominantSets(int N, int[][] edges) {
        // Build adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= N; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        List<Set<Integer>> dominantSets = new ArrayList<>();

        // Generate all subsets of {1..N}
        int totalSubsets = 1 << N; // 2^N subsets
        for (int mask = 1; mask < totalSubsets; mask++) {
            Set<Integer> subset = new HashSet<>();
            for (int i = 0; i < N; i++) {
                if ((mask & (1 << i)) != 0) {
                    subset.add(i + 1);
                }
            }

            if (isDominantSet(subset, N, adj)) {
                dominantSets.add(subset);
            }
        }

        return dominantSets;
    }

    // Check if subset is a Dominant Set
    static boolean isDominantSet(Set<Integer> set, int N, List<List<Integer>> adj) {
        boolean[] covered = new boolean[N + 1];
        
        for (int v : set) {
            covered[v] = true;
            for (int neighbor : adj.get(v)) {
                covered[neighbor] = true;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!covered[i]) return false;
        }

        return true;
    }
}
