#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to; long long w;
};

struct Node {
    int v; long long dist;
    bool operator<(const Node& o) const { return dist > o.dist; }
};

pair<vector<long long>, vector<int>> dijkstra(vector<vector<Edge>>& g, int src) {
    int n = g.size();
    vector<long long> dist(n, LLONG_MAX);
    vector<int> parent(n, -1);
    priority_queue<Node> pq;
    dist[src] = 0;
    pq.push({src, 0});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.dist != dist[cur.v]) continue;
        for (auto& e : g[cur.v]) {
            long long nd = cur.dist + e.w;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                parent[e.to] = cur.v;
                pq.push({e.to, nd});
            }
        }
    }
    return {dist, parent};
}

vector<int> getPath(vector<int>& parent, int t) {
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 6;
    vector<vector<Edge>> g(n);
    auto addEdge = [&](int u, int v, long long w) {
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    };
    addEdge(0,1,7);
    addEdge(0,2,9);
    addEdge(0,5,14);
    addEdge(1,2,10);
    addEdge(1,3,15);
    addEdge(2,3,11);
    addEdge(2,5,2);
    addEdge(3,4,6);
    addEdge(4,5,9);
    auto res = dijkstra(g,0);
    auto dist = res.first;
    auto parent = res.second;
    for(int i=0;i<n;i++){
        cout<<"0 -> "<<i<<" = "<<(dist[i]==LLONG_MAX?-1:dist[i])<<" path:";
        if(dist[i]==LLONG_MAX){cout<<" none\n"; continue;}
        auto path = getPath(parent,i);
        for(int v:path) cout<<" "<<v;
        cout<<"\n";
    }
}
