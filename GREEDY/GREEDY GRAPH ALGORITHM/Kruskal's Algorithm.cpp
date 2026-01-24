#include <iostream>
#include <vector>
#include <algorithm> // For sort
#include <numeric>   // For iota
using namespace std;

// Union-Find data structure to manage connected components
class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // Initialize parent
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            // Union by rank
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Solution {
public:
    /*
    Kruskal's Algorithm Summary:
    1. Sort all edges in non-decreasing order of their weights.
    2. Initialize a Union-Find structure to track connected components.
    3. Iterate through the sorted edges:
       - For each edge, check if it forms a cycle using the Union-Find structure.
       - If it does not create a cycle, include it in the MST and union the two vertices.
    4. Stop when we have included V-1 edges in the MST, where V is the number of vertices.
    5. Return the total weight of the MST.
    */

    // Function to find the sum of weights of edges of the Minimum Spanning Tree (MST)
    int spanningTree(int V, vector<vector<int>> edges) {
        // Sort edges based on their weights
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        UnionFind uf(V);
        int mstWeight = 0; // To store total weight of the MST

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            // Check if adding this edge creates a cycle
            if (uf.find(u) != uf.find(v)) {
                uf.unionSets(u, v); // Union the two sets
                mstWeight += weight; // Add weight to total
            }
        }

        return mstWeight; // Return the total weight of the MST
    }
};

// Function to take graph input from the user
void inputGraph(vector<vector<int>>& edges, int E) {
    cout << "Enter the edges (format: u v w) where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
}

int main() {
    int V, E;

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges; // Edge list representation of the graph

    // Input the graph edges
    inputGraph(edges, E);

    Solution obj;
    int mstWeight = obj.spanningTree(V, edges);
    
    cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}
