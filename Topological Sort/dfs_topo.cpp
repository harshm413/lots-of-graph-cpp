#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, st);
            }
        }

        st.push(node); // Push the node onto the stack after visiting all its neighbors
    }

    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> st;

        // Perform DFS for all unvisited nodes
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited, st);
            }
        }

        // Extract the topological order from the stack
        vector<int> topoOrder;
        while (!st.empty()) {
            topoOrder.push_back(st.top());
            st.pop();
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
    vector<int> topoOrder = solution.topologicalSort(V, adj);

    cout << "Topological Sort Order (DFS-Based): ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
