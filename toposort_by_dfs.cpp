#include <bits/stdc++.h>

using namespace std;

class Solution {
  void findTopoSort(int node, vector < int > & vis, stack < int > & st, vector < int > adj[]) {
    vis[node] = 1;

    for (auto it: adj[node]) {
      if (!vis[it]) {
        findTopoSort(it, vis, st, adj);
      }
    }
    st.push(node);
  }
  public:
    vector < int > topoSort(int N, vector < int > adj[]) {
      stack < int > st;
      vector < int > vis(N, 0);
      for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
          findTopoSort(i, vis, st, adj);
        }
      }
      vector < int > topo;
      while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
      }
      return topo;

    }
};

// { Driver Code Starts.
int main() {

  int N = 6;

  vector < int > adj[5 + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  Solution obj;
  vector < int > res = obj.topoSort(6, adj);

  cout << "Toposort of the given graph is:" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
} 
