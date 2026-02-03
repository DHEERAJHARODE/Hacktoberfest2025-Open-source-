#include <bits/stdc++.h>
using namespace std;

bool dfsSearch(int node, vector<int> adj[], int color[]){
    if(color[node]== -1) color[node] =1;

    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!dfsSearch(it, adj, color)) {
                return false;
            }
        }
        else if(color[it] == color[node]) return false;
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color);
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            if(!dfsSearch(i, adj, color)) {
                return false;
            }
        } 
    }
    return true;
}

void bfsSearch(int v, vector<int> adj[]){
    vector<int> bfs;
    vector<int> vis(v+1, 0);

    for(int i  = 1 ;  i<=v ;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                
                for(auto it : adj[node]){
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

}

int main(){
    //n nodes, m edges
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfsSearch(n, adj);

    return 0;
}
