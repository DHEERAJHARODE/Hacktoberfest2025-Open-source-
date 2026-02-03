#include<bits/stdc++.h>
using namespace std;


class Graph
{
	int V12; // No. of vertices


	vector<list<int>> adj;
public:
	Graph(int V12); // Constructor


	void addEdge(int v12, int w12);


	void BFS(int s);
};

Graph::Graph(int V12)
{
	this->V12 = V12;
	adj.resize(V12);
}

void Graph::addEdge(int v12, int w12)
{
	adj[v12].push_back(w12); 
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V12,false);


	list<int> queue;


	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{

		s = queue.front();
		cout << s << " ";
		queue.pop_front();


		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}


int main()
{

	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
