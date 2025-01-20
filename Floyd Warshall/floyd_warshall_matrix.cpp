#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Problem: All-Pairs Shortest Path (Using Floyd-Warshall Algorithm)

Description:
Given a directed graph with n vertices and m edges, find the shortest paths between every pair of vertices. 
If there is no path between two vertices, return -1.

Input:
- The first line contains two integers n and m — the number of vertices and the number of edges in the graph.
- The next m lines contain three integers u, v, and w — indicating an edge from vertex u to vertex v with weight w (1 ≤ u, v ≤ n, 0 ≤ w ≤ 100).
- It is guaranteed that there are no negative weight edges.

Output:
- Output a n x n matrix where the value at row i, column j represents the shortest path distance from vertex i to vertex j. If no path exists, output -1.

Example Input:
4 5
1 2 3
1 3 4
2 3 2
3 4 1
4 1 7

Example Output:
0 3 4 5
3 0 2 3
4 2 0 1
5 3 1 0

Solution:
The Floyd-Warshall algorithm is used to compute the shortest paths between all pairs of vertices.
It iteratively updates the distance matrix by considering all possible intermediate vertices for every pair of vertices.

Steps:
1. Initialize the distance matrix with infinity (INT_MAX) and set the diagonal to 0.
2. For each edge (u, v, w), set dist[u][v] to w.
3. Use three nested loops to update the distance matrix based on the intermediate vertex.
4. Replace any remaining INT_MAX values with -1 to indicate no path exists.
*/

void floydWarshall(int n, vector<vector<int>>& dist) {
    // Floyd-Warshall Algorithm: Iteratively update the distance matrix
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If a path exists from i to k and from k to j, try to improve the path from i to j through k
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices (n) and number of edges (m)

    // Initialize the distance matrix with infinity (INT_MAX)
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Distance from each vertex to itself is 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Input the edges: for each edge (u, v, w), set dist[u-1][v-1] = w
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = min(dist[u - 1][v - 1], w);  // In case of multiple edges between the same pair of nodes
    }

    // Run Floyd-Warshall algorithm to compute shortest paths
    floydWarshall(n, dist);

    // Output the distance matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // If there is no path, print -1
            if (dist[i][j] == INT_MAX) {
                cout << -1 << " ";  
            } else {
                // Otherwise, print the shortest path distance
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
