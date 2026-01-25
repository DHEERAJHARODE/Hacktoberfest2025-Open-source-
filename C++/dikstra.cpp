#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // Pair to store vertex and its distance

// Function to implement Dijkstra's Algorithm
void dijkstra(int source, vector<vector<pii>>& graph, int V) {
    // Create a priority queue to store the vertices that are being processed
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Create a vector to store distances from source
    vector<int> dist(V, INT_MAX);

    // Push the source node into the queue and set its distance to 0
    pq.push({0, source});
    dist[source] = 0;

    // While the priority queue is not empty
    while (!pq.empty()) {
        // Get the vertex with the smallest distance
        int u = pq.top().second;
        pq.pop();

        // Process all the adjacent vertices of the current vertex
        for (auto &edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If there's a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from source
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> graph(V);

    // Add edges (vertex1, vertex2, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({0, 7});
    graph[3].push_back({2, 6});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    int source = 0; // Starting point

    dijkstra(source, graph, V);

    return 0;
}
