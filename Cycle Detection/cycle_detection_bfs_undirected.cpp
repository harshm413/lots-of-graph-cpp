#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using BFS
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (bfsCheckCycle(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // Helper function to check for a cycle using BFS
    bool bfsCheckCycle(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> q; // {node, parent}
        q.push({start, -1});
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    // If the neighbor is visited and is not the parent, a cycle is detected
                    return true;
                }
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
