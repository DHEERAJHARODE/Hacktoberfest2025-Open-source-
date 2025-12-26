#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
	int v;
	vector<int> *adj;
	void findTopologicalSort(int node, vector<bool> &visited, stack<int> &s);
public:
	Graph(int v) {
		this->v = v;
		adj = new vector<int>[v];
	}
	void addEdge(int v, int u) {
		adj[v].push_back(u);
	}
	vector<int> topologicalSort();
};

void Graph::findTopologicalSort(int node, vector<bool> &visited, stack<int> &s) {
	visited[node] = true;
	for(auto &i : adj[node]) {
		if(!visited[i])
			findTopologicalSort(i, visited, s);
	}
	s.push(node);
}

vector<int> Graph::topologicalSort() {
	stack<int> s;
	vector<bool> visited(v, false);
	for(int i = 0; i < v; ++i) {
		if(!visited[i])
			findTopologicalSort(i, visited, s);
	}
	vector<int> topo;
	while(!s.empty()) {
		topo.push_back(s.top());
		s.pop();
	}
	return topo;
}

int main() {
	Graph g(6);
	g.addEdge(5, 0);
	g.addEdge(5, 2);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	vector<int> topo = g.topologicalSort();
	cout << "Topological Sort: ";
	for(auto &i: topo)
		cout << i << " ";
	cout << endl;
	return 0;
}
