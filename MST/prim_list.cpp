#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
Problem: Prim's Algorithm for Minimum Spanning Tree (MST) in an Undirected Graph (Using Edge List)

Description:
Given an undirected graph with n vertices and m edges, and edge weights, find the Minimum Spanning Tree (MST) using Prim's algorithm.

Input:
- The first line contains two integers n (number of vertices) and m (number of edges).
- The next m lines contain three integers u, v, and w, indicating an undirected edge between vertex u and vertex v with weight w.

Output:
- Print the edges in the MST and the total weight of the MST.
*/

void prim(int n, vector<vector<int>>& edges) {
    vector<bool> inMST(n, false);  // To track vertices included in MST
    vector<int> key(n, INT_MAX);   // Stores the minimum weight edge for each vertex
    vector<int> parent(n, -1);     // Parent array to store the MST

    key[0] = 0;  // Start from vertex 0
    int mstWeight = 0;

    for (int count = 0; count < n - 1; ++count) {
        // Find the vertex with the minimum key value that is not yet included in MST
        int u = -1;
        for (int i = 0; i < n; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;  // Include the vertex in MST
        mstWeight += key[u];  // Add the key value to the total weight

        // Update key and parent values of adjacent vertices of u
        for (auto& edge : edges) {
            int v = -1;
            int w = -1;
            if (edge[0] == u) {
                v = edge[1];
                w = edge[2];
            } else if (edge[1] == u) {
                v = edge[0];
                w = edge[2];
            }

            if (v != -1 && !inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // Output the MST edges and total weight
    for (int i = 1; i < n; ++i) {
        cout << parent[i] + 1 << " " << i + 1 << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices and edges

    vector<vector<int>> edges;  // Edge list for the graph

    // Input the edges (undirected)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u - 1, v - 1, w});  // Add edge u-v with weight w
    }

    prim(n, edges);  // Run Prim's algorithm
    return 0;
}

// Prim's algorithm is designed to find the Minimum Spanning Tree (MST) of a graph, and it is typically used in undirected graphs.