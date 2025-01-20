#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/*
Problem: Dijkstra's Algorithm for Shortest Path in an Undirected Graph (Using Adjacency List)

Description:
Given an undirected graph with n vertices and m edges, and a source vertex, find the shortest path from the source to all other vertices using Dijkstra's algorithm.

Input:
- The first line contains two integers n (number of vertices) and m (number of edges).
- The next m lines contain two integers u, v, and w, indicating an undirected edge between vertex u and vertex v with weight w.
- The last line contains an integer source, the starting vertex for Dijkstra's algorithm.

Output:
- Print the shortest distance from the source vertex to every other vertex.

Solution:
Dijkstra's algorithm works by iteratively selecting the vertex with the minimum tentative distance and updating the distances of its neighbors. The adjacency list is used for storing the graph.

To make this directed, remove the line: `adjList[v-1].push_back({u-1, w});`
*/

// Dijkstra's algorithm using priority queue (min-heap)
void dijkstra(int n, int source, vector<vector<pair<int, int>>>& adjList) {
    vector<int> dist(n, INT_MAX);  // Distance from source to each vertex
    dist[source] = 0;
    
    // Min-heap to store vertices with their current shortest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});  // Push the source with distance 0
    
    while (!pq.empty()) {
        int u = pq.top().second;  // Vertex with the minimum distance
        pq.pop();
        
        // Traverse the neighbors of vertex u
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;  // Neighbor vertex
            int weight = neighbor.second;  // Edge weight
            
            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
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

    // Adjacency List initialization
    vector<vector<pair<int, int>>> adjList(n);

    // Input edges (undirected)
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u - 1].push_back({v - 1, w});  // Add edge u-v with weight w
        adjList[v - 1].push_back({u - 1, w});  // Add edge v-u with weight w (removal of this line makes it directed)
    }

    int source;
    cin >> source;  // Source vertex for Dijkstra
    dijkstra(n, source - 1, adjList);  // Run Dijkstra's algorithm from the source

    return 0;
}

// This code works for an undirected graph. For a directed graph, 
// remove the line "adjList[v-1].push_back({u-1, w});" from the input.

// Works on weighted.