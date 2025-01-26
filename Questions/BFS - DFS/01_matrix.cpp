#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Push all 0 cells into the queue and initialize their distance to 0
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                // Check for valid cells and update distance if unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && dist[newRow][newCol] == INT_MAX) {
                    dist[newRow][newCol] = dist[row][col] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution solution;

    // Input matrix
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    // Get the result
    vector<vector<int>> result = solution.updateMatrix(mat);

    // Print the result
    cout << "Updated Matrix (Distances from nearest 0):\n";
    for (const auto& row : result) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
