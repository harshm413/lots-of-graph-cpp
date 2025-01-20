#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Kruskal's Algorithm for Minimum Spanning Tree (MST) in an Undirected Graph (Using Adjacency Matrix)

Description:
Given an undirected graph with n vertices and m edges, and edge weights, find the Minimum Spanning Tree (MST) using Kruskal's algorithm.

Input:
- The first line contains two integers n (number of vertices) and m (number of edges).
- The next m lines contain three integers u, v, and w, indicating an undirected edge between vertex u and vertex v with weight w.

Output:
- Print the edges in the MST and the total weight of the MST.
*/

class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Kruskal's Algorithm to find MST
void kruskal(int n, vector<vector<int>>& adjMatrix) {
    vector<pair<int, pair<int, int>>> edges;  // To store edges (weight, u, v)
    
    // Extract edges from the adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adjMatrix[i][j] != 0) {
                edges.push_back({adjMatrix[i][j], {i, j}});
            }
        }
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int mstWeight = 0;
    vector<pair<int, int>> mstEdges;

    // Run Kruskal's algorithm
    for (auto& edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;
        
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mstEdges.push_back({u, v});
            mstWeight += w;
        }
    }

    // Output the MST edges and total weight
    for (auto& edge : mstEdges) {
        cout << edge.first + 1 << " " << edge.second + 1 << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices and edges

    // Adjacency matrix for undirected graph
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Input the edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u - 1][v - 1] = w;  // u-v with weight w
        adjMatrix[v - 1][u - 1] = w;  // v-u with weight w (undirected)
    }

    kruskal(n, adjMatrix);  // Run Kruskal's algorithm
    return 0;
}

// Kruskal's algorithm is designed to find the Minimum Spanning Tree (MST) of a graph, and it is typically used in undirected graphs.