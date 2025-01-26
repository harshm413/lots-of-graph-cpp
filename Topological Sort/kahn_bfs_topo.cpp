#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        vector<int> topoOrder;

        // Calculate indegree for each vertex
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // Add vertices with indegree 0 to the queue
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the vertices
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the number of nodes in the topological order is less than V, there's a cycle
        if (topoOrder.size() != V) {
            throw runtime_error("The graph is not a DAG; it contains a cycle.");
        }

        return topoOrder;
    }
};

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj = {
        {2, 3}, // Edges from node 0
        {3, 4}, // Edges from node 1
        {},     // Edges from node 2
        {5},    // Edges from node 3
        {5},    // Edges from node 4
        {}      // Edges from node 5
    };

    Solution solution;
    try {
        vector<int> topoOrder = solution.topologicalSort(V, adj);
        cout << "Topological Sort Order (Kahn's Algorithm): ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
