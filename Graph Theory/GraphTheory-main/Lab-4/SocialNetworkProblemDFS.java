import java.util.*;

public class SocialNetworkProblemDFS {
    public static void main(String[] args) {
        int[][] adj = {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 1, 1},
            {0, 0, 1, 1}
        };
        int n = adj.length;
        int count = 0;
        HashSet<Integer> visited = new HashSet<>();

        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                DFS(adj, i, visited);
                count++;
            }
        }
        System.out.println("Count = " + count);
    }

    public static void DFS(int[][] adj, int curr, HashSet<Integer> visited) {
        Stack<Integer> stack = new Stack<>();
        stack.push(curr);

        while (!stack.isEmpty()) {
            int current = stack.pop();
            if (!visited.contains(current)) {
                visited.add(current);
                for (int k = 0; k < adj.length; k++) {
                    if (adj[current][k] == 1 && !visited.contains(k)) {
                        stack.push(k);
                    }
                }
            }
        }
    }
}
