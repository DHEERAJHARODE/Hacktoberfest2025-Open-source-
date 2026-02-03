// A C++ program for Prim's Minimum Spanning Tree(MST)

#include <bits/stdc++.h>
using namespace std;
// Number of vertices in the graph
#define V 5

int MinKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void MST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void PrimMST(int graph[V][V])
{
	// Array to store constructed MST
	int parent[V];

	int key[V];


	bool mstSet[V];

	
	for (int j = 0; j < V; j++)
		key[j] = INT_MAX, mstSet[j] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) {
		
		int u = MinKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	MST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	
	PrimMST(graph);

	return 0;
}

