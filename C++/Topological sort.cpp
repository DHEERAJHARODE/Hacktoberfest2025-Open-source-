#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void topologicalSort();
    
private:
    int vertices;
    vector<vector<int>> adjacencyList;
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stack);
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stack) {
    visited[v] = true;
    for (int neighbor : adjacencyList[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, stack);
        }
    }
    stack.push(v);
}

void Graph::topologicalSort() {
    vector<bool> visited(vertices, false);
    stack<int> stack;

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, stack);
        }
    }

    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort: ";
    g.topologicalSort();

    return 0;
}
