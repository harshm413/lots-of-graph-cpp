#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Problem: Dijkstra's Algorithm for Shortest Path in an Undirected Graph (Using Adjacency Matrix)

Description:
Given an undirected graph with n vertices and m edges, and a source vertex, find the shortest path from the source to all other vertices using Dijkstra's algorithm.

Input:
- The first line contains two integers n (number of vertices) and m (number of edges).
- The next m lines contain two integers u, v, and w, indicating an undirected edge between vertex u and vertex v with weight w.
- The last line contains an integer source, the starting vertex for Dijkstra's algorithm.

Output:
- Print the shortest distance from the source vertex to every other vertex.

Solution:
Dijkstra's algorithm works by iteratively selecting the vertex with the minimum tentative distance and updating the distances of its neighbors. The adjacency matrix is used for storing the graph.

To make this directed, remove the line: `adjMatrix[v-1][u-1] = w;`
*/

// Dijkstra's algorithm using adjacency matrix
void dijkstra(int n, int source, vector<vector<int>>& adjMatrix) {
    vector<int> dist(n, INT_MAX);  // Distance from source to each vertex
    dist[source] = 0;
    
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; ++i) {
        // Find the vertex with the minimum distance
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        visited[u] = true;
        
        // Update distances of adjacent vertices
        for (int v = 0; v < n; ++v) {
            if (adjMatrix[u][v] != -1 && !visited[v] && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
            }
        }
    }

    // Output the shortest distances
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << -1 << " ";  // No path to vertex i
        } else {
            cout << dist[i] << " ";
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices and edges

    // Initialize adjacency matrix with -1 (indicating no edge)
    vector<vector<int>> adjMatrix(n, vector<int>(n, -1));

    // Input edges (undirected)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u - 1][v - 1] = w;  // Add edge u-v with weight w
        adjMatrix[v - 1][u - 1] = w;  // Add edge v-u with weight w (removal of this line makes it directed)
    }

    int source;
    cin >> source;  // Source vertex for Dijkstra
    dijkstra(n, source - 1, adjMatrix);  // Run Dijkstra's algorithm from the source

    return 0;
}

// This code works for an undirected graph. For a directed graph, 
// remove the line "adjMatrix[v-1][u-1] = w;" from the input.

// Works on weighted.