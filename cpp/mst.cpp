#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int V = 5; // Number of vertices in the graph

int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX, minIndex = -1;
    
    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void printMST(int parent[], vector<vector<int>>& graph) {
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
    }
}

void primMST(vector<vector<int>>& graph) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    // Initialize all keys as infinity and mstSet[] as false
    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start with the first vertex
    key[0] = 0;     
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "Minimum Spanning Tree using Prim's algorithm:" << endl;
    primMST(graph);

    return 0;
}
