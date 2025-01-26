#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using DFS
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfsCheckCycle(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // Helper function to check for a cycle using DFS
    bool dfsCheckCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // Recur for the unvisited neighbor
                if (dfsCheckCycle(neighbor, node, adj, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // If visited and not the parent, cycle exists
                return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Create undirected graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); // Adding edge 4-1 creates a cycle

    Solution solution;
    if (solution.isCycle(V, adj)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle detected in the graph.\n";
    }

    return 0;
}
