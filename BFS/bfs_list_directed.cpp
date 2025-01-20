#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

/*
Problem: Breadth-First Search (BFS) in a Directed Graph (Using Adjacency List)

Description:
Given a directed graph with n vertices and m edges, perform a Breadth-First Search (BFS) starting from a given source vertex. 
Print the distance from the source vertex to each other vertex. If a vertex is not reachable from the source, print -1 for that vertex.

Input:
- The first line contains two integers n (number of vertices) and m (number of edges).
- The next m lines contain two integers u and v, indicating a directed edge from vertex u to vertex v.
- The last line contains an integer source, the starting vertex for BFS.

Output:
- For each vertex, print the shortest distance from the source vertex. If a vertex is unreachable, print -1.

Example Input:
4 4
1 2
1 3
2 4
3 4
1

Example Output:
0 1 1 2

Solution:
In the BFS algorithm, we start from a given source vertex and explore all its neighbors at the present depth before moving on to vertices at the next depth level. We use a queue to store the vertices to be explored and update the distance for each vertex. If a vertex is reachable, we update its distance; otherwise, we leave it as -1.
*/

void bfs(int n, vector<vector<int>>& adjList, int source) {
    vector<int> dist(n, -1);  // Initialize distance of all vertices as -1
    queue<int> q;
    
    dist[source] = 0;  // Distance from source to itself is 0
    q.push(source);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Check all neighbors of u
        for (int v : adjList[u]) {
            if (dist[v] == -1) {  // If v is not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // Print the distance for each vertex
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of vertices (n) and edges (m)

    // Adjacency List initialization
    vector<vector<int>> adjList(n);

    // Input edges (directed)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u - 1].push_back(v - 1);  // Add directed edge u -> v
    }

    int source;
    cin >> source;  // Source vertex for BFS
    bfs(n, adjList, source - 1);  // Call BFS starting from the source (adjusted for 0-indexing)

    return 0;
}

// This code works for a directed graph. For an undirected graph, 
// you would need to modify how edges are added in the adjacency list.
