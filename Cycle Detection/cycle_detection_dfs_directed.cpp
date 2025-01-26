#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to detect a cycle in a directed graph
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfsCheckCycle(i, adj, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // Helper function to perform DFS and detect cycles
    bool dfsCheckCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheckCycle(neighbor, adj, visited, recStack)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                // If the neighbor is in the recursion stack, a cycle is detected
                return true;
            }
        }

        recStack[node] = false; // Remove node from recursion stack
        return false;
    }
};

int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);

    // Add edges to the directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Creates a cycle

    Solution solution;
    if (solution.isCyclic(V, adj)) {
        cout << "Cycle detected in the directed graph.\n";
    } else {
        cout << "No cycle detected in the directed graph.\n";
    }

    return 0;
}
