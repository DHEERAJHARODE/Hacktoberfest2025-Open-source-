//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    /*
    Prim's Algorithm Summary:
    1. Initialize a priority queue (min-heap) to keep track of edges and their weights.
    2. Start from an arbitrary vertex (usually vertex 0) and add it to the MST.
    3. While there are vertices not included in the MST:
       a. Extract the edge with the smallest weight from the priority queue.
       b. If the vertex is already included in the MST, continue.
       c. Add the weight of this edge to the total MST weight.
       d. Mark the vertex as included in the MST.
       e. For all adjacent vertices of the extracted vertex, if they are not in the MST, add them to the priority queue.
    4. Repeat until all vertices are included in the MST.
    5. Return the total weight of the MST.
    */
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         // To keep track of nodes included in MST
        vector<bool> inMST(V, false);
        
        // Min-heap (priority queue) to pick the minimum weight edge at each step
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Starting with node 0 and edge weight 0
        pq.push({0, 0});
        
        int mstWeight = 0;  // To store the total weight of the MST
        
        // Loop until we include all nodes in the MST
        while (!pq.empty()) {
            // Extract the minimum weight edge
            int u = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            
            // If the node is already in the MST, we skip
            if (inMST[u]) continue;
            
            // Add the weight to the total MST weight
            mstWeight += weight;
            
            // Mark the node as included in the MST
            inMST[u] = true;
            
            // For all adjacent vertices of the extracted vertex
            for (auto it : adj[u]) {
                int v = it[0];
                int w = it[1];
                
                // If the adjacent vertex is not in the MST, push it to the priority queue
                if (!inMST[v]) {
                    pq.push({w, v});
                }
            }
        }
        
        return mstWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends