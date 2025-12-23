#include<bits/stdc++.h>
using namespace std;

//prims algorithm brute force
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    int parent[n];
    int key[n];
    bool mstset[n];
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        mstset[i]=false;
        parent[i]=-1;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++){//because n-1 edges
    
    int mini=INT_MAX;
    int u;
    for(int v=0;v<n;v++){
        if(mstset[v]==false && key[v]<mini){
            mini=key[v];
            u=v;
        }
    }
    mstset[u]=true;
    for(auto it:adj[u]){
        int v=it.first;
        int weight=it.second;
        if(mstset[v]==false && weight<key[v]){
            key[v]=weight;
            parent[v]=u;
        }
    }

    }
    for(int i=0;i<n;i++){
        cout<<parent[i]<<" ";
    }
    return 0;
}
