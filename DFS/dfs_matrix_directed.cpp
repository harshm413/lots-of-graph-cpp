#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem: Depth-First Search (DFS) in a Directed Graph (Using Adjacency Matrix)

Description:
Given a directed graph with n vertices and m edges, perform a Depth-First Search (DFS) starting from a given source vertex.
Print the visited vertices during DFS traversal.

Input:
- The first line contains two integers n (number of vertices) and m (number of edges).
- The next m lines contain two integers u and v, indicating a directed edge from vertex u to vertex v.
- The last line contains an integer source, the starting vertex for DFS.

Output:
- Print the vertices visited during the DFS traversal starting from the source vertex.

Solution:
DFS explores a graph by visiting a vertex and recursively visiting all its adjacent vertices before backtracking. The adjacency matrix is used for storing the graph, and a DFS function recursively traverses the graph.
*/

// Recursive DFS function
void dfs_recursive(int u, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[u] = true;
    cout << u + 1 << " ";  // Print vertex (adjusted for 1-indexing)

    // Visit all the neighbors of vertex u
    for (int v = 0; v < adjMatrix.size(); ++v) {
        if (adjMatrix[u][v] == 1 && !visited[v]) {
            dfs_recursive(v, adjMatrix, visited);
        }
    }
}

// Iterative DFS function using a stack
void dfs_iterative(int u, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    stack<int> stk;
    stk.push(u);
    visited[u] = true;

    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        cout << node + 1 << " ";  // Print vertex (adjusted for 1-indexing)

        // Visit all unvisited neighbors of the current node
        for (int v = 0; v < adjMatrix.size(); ++v) {
            if (adjMatrix[node][v] == 1 && !visited[v]) {
                visited[v] = true;
                stk.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices (n) and edges (m)

    // Adjacency Matrix initialization
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));  // Initialize as 0

    // Input edges (directed)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u - 1][v - 1] = 1;  // Add directed edge u -> v
    }

    int source;
    cin >> source;  // Source vertex for DFS
    vector<bool> visited(n, false);  // Keep track of visited vertices

    cout << "Recursive DFS Traversal: ";
    dfs_recursive(source - 1, adjMatrix, visited);  // Call recursive DFS

    // Reset visited for iterative DFS
    fill(visited.begin(), visited.end(), false);

    cout << "\nIterative DFS Traversal: ";
    dfs_iterative(source - 1, adjMatrix, visited);  // Call iterative DFS

    return 0;
}

// This code works for a directed graph. For an undirected graph, 
// you would need to modify how edges are added in the adjacency matrix.
