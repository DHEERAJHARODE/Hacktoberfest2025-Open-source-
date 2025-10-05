#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define V 5   // Number of vertices

// DFS utility function
void dfs(int u, bool visited[], int skip, int graph[V][V]) {
    visited[u] = true;
    for (int v = 0; v < V; v++) {
        if (graph[u][v] && v != skip && !visited[v]) {
            dfs(v, visited, skip, graph);
        }
    }
}

int main() {
    // Graph edges
    int edges[][2] = {
        {0, 1}, {0, 2}, {2, 3}, {2, 4}
    };
    int E = sizeof(edges) / sizeof(edges[0]);

    // Build adjacency matrix
    int graph[V][V] = {0};
    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Find reachable nodes without removing anything
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(0, visited, -1, graph);

    int fullCount = 0;
    for (int i = 0; i < V; i++)
        if (visited[i]) fullCount++;

    printf("Cut Vertices:\n");

    // Try removing each vertex
    for (int skip = 0; skip < V; skip++) {
        memset(visited, false, sizeof(visited));

        int start = (skip == 0) ? 1 : 0;
        dfs(start, visited, skip, graph);

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (i != skip && visited[i]) count++;
        }

        if (count < fullCount - 1) {
            printf("%d\n", skip);
        }
    }

    return 0;
}
