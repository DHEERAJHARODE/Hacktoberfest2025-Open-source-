//  Prob. 1 Find and print all cut-vertices (articulation points) in an undirected graph. 
import java.util.*;

public class FindCutVertices {
    static void dfs(int u, boolean[] visited, List<List<Integer>> g, int skip) {
        visited[u] = true;
        for (int v : g.get(u)) {
            if (!visited[v] && v != skip) {
                dfs(v, visited, g, skip);
            }
        }
    }

    public static void main(String[] args) {
        int V = 5;
        int[][] edges = {
            {0, 1}, {0, 2}, {2, 3}, {2, 4}
        };

        // Build adjacency list
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < V; i++) g.add(new ArrayList<>());
        for (int[] e : edges) {
            g.get(e[0]).add(e[1]);
            g.get(e[1]).add(e[0]);
        }

        // Count reachable nodes without removing anything
        boolean[] visited = new boolean[V];
        dfs(0, visited, g, -1);
        int fullCount = 0;
        for (boolean b : visited) if (b) fullCount++;

        System.out.println("Cut Vertices:");
        for (int skip = 0; skip < V; skip++) {
            Arrays.fill(visited, false);

            // pick a start node that's not removed
            int start = (skip == 0) ? 1 : 0;
            dfs(start, visited, g, skip);

            int count = 0;
            for (int i = 0; i < V; i++) {
                if (i != skip && visited[i]) count++;
            }

            if (count < fullCount - 1) {
                System.out.println(skip);
            }
        }
    }
}
