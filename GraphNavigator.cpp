#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class GraphNavigator {
private:
    int vertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    GraphNavigator(int v) : vertices(v), adjacencyList(v) {}

    void addConnection(int source, int destination, int distance) {
        adjacencyList[source].push_back(std::make_pair(destination, distance));
        adjacencyList[destination].push_back(std::make_pair(source, distance)); // Assuming an undirected graph
    }

    void findShortestPaths(int startNode) {
        std::vector<int> distances(vertices, INT_MAX);
        distances[startNode] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, startNode));

        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjacencyList[current]) {
                int next = neighbor.first;
                int weight = neighbor.second;

                if (distances[current] != INT_MAX && distances[current] + weight < distances[next]) {
                    distances[next] = distances[current] + weight;
                    pq.push(std::make_pair(distances[next], next));
                }
            }
        }

        std::cout << "Shortest distances from node " << startNode << ":\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << "To node " << i << ": " << distances[i] << "\n";
        }
    }
};

int main() {
    GraphNavigator navigator(5);

    navigator.addConnection(0, 1, 2);
    navigator.addConnection(0, 2, 4);
    navigator.addConnection(1, 2, 1);
    navigator.addConnection(1, 3, 7);
    navigator.addConnection(2, 4, 3);
    navigator.addConnection(3, 4, 1);

    navigator.findShortestPaths(0);

    return 0;
}
