// 11. Prob.1 Implement a solution to find a shortest path in a network (Dijkstra’s Algorithm). 
 
// Given: A weighted graph and a source vertex 
// Find: The shortest distance from the source to all other vertices. 
 
// Hint:  
// Mark all distances as infinity except the source (distance = 0). 
// Use a priority queue or greedy selection to always choose the closest unvisited node. 
// Update distances to neighbors. 
// Repeat until all nodes are visited.

// Enter number of vertices: 5
// Enter number of edges: 6
// Enter edges (u v w):
// 0 1 10
// 0 2 3
// 1 2 1
// 1 3 2
// 2 3 8
// 3 4 7
// Enter source vertex: 0

import java.util.*;

public class DijkstraAlgorithm {

    static class Edge {
        int vertex, weight;
        Edge(int v, int w) {
            vertex = v;
            weight = w;
        }
    }

    public static void dijkstra(List<List<Edge>> graph, int source) {
        int n = graph.size();
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];

        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[source] = 0;

        // Min-Heap Priority Queue (distance, node)
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, source});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int u = current[1];

            if (visited[u]) continue;
            visited[u] = true;

            for (Edge edge : graph.get(u)) {
                int v = edge.vertex;
                int newDist = dist[u] + edge.weight;

                if (!visited[v] && newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.offer(new int[]{dist[v], v});
                }
            }
        }

        // Print shortest distances
        System.out.println("Shortest distances from source " + source + ":");
        for (int i = 0; i < n; i++) {
            if (dist[i] == Integer.MAX_VALUE)
                System.out.println("To " + i + " -> INF");
            else
                System.out.println("To " + i + " -> " + dist[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input graph
        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();
        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < V; i++) graph.add(new ArrayList<>());

        System.out.println("Enter edges (u v w):");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            graph.get(u).add(new Edge(v, w));
            graph.get(v).add(new Edge(u, w)); // if undirected
        }

        System.out.print("Enter source vertex: ");
        int source = sc.nextInt();

        dijkstra(graph, source);
        sc.close();
    }
}
