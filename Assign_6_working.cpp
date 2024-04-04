#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjacencyList;

public:
    void addEdge(string fromVertex, string toVertex, int cost) {
        adjacencyList[fromVertex].push_back(make_pair(toVertex, cost));
    }

    unordered_map<string, int> calculateInDegree() {
        unordered_map<string, int> inDegree;
        for (auto& vertex : adjacencyList) {
            inDegree[vertex.first] = 0;
        }

        for (auto& vertex : adjacencyList) {
            for (auto& edge : vertex.second) {
                inDegree[edge.first]++;
            }
        }

        return inDegree;
    }

    unordered_map<string, int> calculateOutDegree() {
        unordered_map<string, int> outDegree;
        for (auto& vertex : adjacencyList) {
            outDegree[vertex.first] = vertex.second.size();
        }
        return outDegree;
    }

    bool isConnected() {
        unordered_set<string> visited;
        dfs(adjacencyList.begin()->first, visited);
        return visited.size() == adjacencyList.size();
    }

    void dfs(string vertex, unordered_set<string>& visited) {
        visited.insert(vertex);
        for (auto& edge : adjacencyList[vertex]) {
            if (visited.find(edge.first) == visited.end()) {
                dfs(edge.first, visited);
            }
        }
    }

    void printGraph() {
        for (auto& vertex : adjacencyList) {
            cout << vertex.first << " -> ";
            for (auto& edge : vertex.second) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge("A", "B", 5);
    g.addEdge("B", "C", 7);
    g.addEdge("C", "A", 3);
    g.addEdge("C", "D", 8);

    g.printGraph();

    auto inDegree = g.calculateInDegree();
    auto outDegree = g.calculateOutDegree();
    cout << "In-degree: ";
    for (auto& pair : inDegree) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << endl;

    cout << "Out-degree: ";
    for (auto& pair : outDegree) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << endl;

    cout << "Is connected: " << (g.isConnected() ? "true" : "false") << endl;

    return 0;
}
