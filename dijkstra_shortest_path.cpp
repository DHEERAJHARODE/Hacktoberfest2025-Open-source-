#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>

using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

class DijkstraAlgorithm {
private:
    vector<vector<Edge>> graph;  // Adjacency list representation
    int V;  // Number of vertices

public:
    DijkstraAlgorithm(int vertices) : V(vertices) {
        graph.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int from, int to, int weight) {
        graph[from].emplace_back(to, weight);
        graph[to].emplace_back(from, weight);  // For undirected graph
    }

    // Implement Dijkstra's algorithm
    vector<int> shortestPath(int source) {
        // Priority queue to store vertices that are being preprocessed
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Vector to store shortest distance values
        vector<int> dist(V, numeric_limits<int>::max());
        
        // Insert source itself in priority queue and initialize its distance as 0
        pq.push(make_pair(0, source));
        dist[source] = 0;
        
        // Vector to store the shortest path tree
        vector<int> parent(V, -1);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // For all adjacent vertices of u
            for (const Edge& edge : graph[u]) {
                int v = edge.to;
                int weight = edge.weight;

                // If there is a shorter path to v through u
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }

    // Print the shortest path from source to destination
    void printPath(int source, int destination) {
        vector<int> dist = shortestPath(source);
        
        cout << "Shortest distances from vertex " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To vertex " << i << ": ";
            if (dist[i] == numeric_limits<int>::max()) {
                cout << "INF\n";
            } else {
                cout << dist[i] << "\n";
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    DijkstraAlgorithm graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 6);
    graph.addEdge(4, 5, 3);

    cout << "Graph representation for Dijkstra's Algorithm\n";
    cout << "============================================\n";
    
    // Find and print shortest paths from vertex 0
    graph.printPath(0, 5);

    return 0;
}