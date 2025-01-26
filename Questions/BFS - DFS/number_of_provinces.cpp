#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

// Function to find the number of provinces
int findNumberOfProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<vector<int>> adjList(n);

    // Convert adjacency matrix to adjacency list
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isConnected[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
            }
        }
    }

    vector<bool> visited(n, false);
    int provinces = 0;

    // Traverse all nodes using DFS
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++provinces;
            dfs(i, adjList, visited);
        }
    }

    return provinces;
}

int main() {
    // Example input: adjacency matrix
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int result = findNumberOfProvinces(isConnected);
    cout << "Number of Provinces: " << result << endl;

    return 0;
}
