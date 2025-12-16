// Dijkstra algorithm --> used to find the shortest distance from the source to all vertices in the given graph
// It is a distance minimisation problem based on greedy approach
// Every time a node with shortest distance till now is picked and then its neighbours are relaxed
// LIMITATION: It fails when edges have negative weights

// Time Complexity: O(ElogV)

#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

void dijkstra(int s, vector<int> &dist, vector<vector<pii>> &graph)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[s] = 0;

    pq.push({dist[s], s});

    while (!pq.empty())
    {
        pii cur = pq.top();
        int u = cur.second;
        int d = cur.first;
        pq.pop();
        if (dist[u] < d)
            continue;

        for (auto p : graph[u])
        {
            int v = p.first;
            int w = p.second;
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pii>> graph(n);
    for (int i = 0; i < e; i++)
    {
        int src, des, wei;
        cin >> src >> des >> wei;
        graph[src].push_back({des, wei});
        graph[des].push_back({src, wei});
    }
    int source;
    cin >> source;
    vector<int> distance(n + 1, INT_MAX);
    dijkstra(source, distance, graph);
    cout << "Distance of each node from " << source << " is:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (distance[i] != INT_MAX)
        {
            cout << i << " -> " << distance[i] << endl;
        }
        else
            cout << i << " -> Not reachable" << endl;
    }
    return 0;
}