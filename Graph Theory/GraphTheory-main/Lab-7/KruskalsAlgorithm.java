import java.util.*;

public class KruskalsAlgorithm {

    // Find with path compression
    static int find(int[] parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    // Union by rank
    static void union(int[] parent, int[] rank, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py) {
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }

    public static int kruskalsMST(int V, int[][] edges) {
        // Sort edges by weight
        Arrays.sort(edges, (a, b) -> Integer.compare(a[2], b[2]));

        int[] parent = new int[V];
        int[] rank = new int[V];
        for (int i = 0; i < V; i++) parent[i] = i;

        int cost = 0, count = 0;
        List<String> mstEdges = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (find(parent, u) != find(parent, v)) {
                union(parent, rank, u, v);
                cost += w;
                mstEdges.add(u + " - " + v + " : " + w);
                if (++count == V - 1) break;
            }
        }

        System.out.println("Edges in MST:");
        for (String edge : mstEdges) {
            System.out.println(edge);
        }

        return cost;
    }

    public static void main(String[] args) {
        int[][] edges = {
            {0, 1, 10},
            {1, 3, 15},
            {2, 3, 4},
            {2, 0, 6},
            {0, 3, 5}
        };

        int minCost = kruskalsMST(4, edges);
        System.out.println("Minimum Cost of MST: " + minCost);
    }
}
