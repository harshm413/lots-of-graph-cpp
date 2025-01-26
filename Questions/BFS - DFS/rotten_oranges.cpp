#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the minimum time to rot all oranges using BFS
int bfsRottenOranges(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q; // Queue to store the rotten oranges
    int freshCount = 0;      // Count of fresh oranges
    int minutes = 0;         // Time required to rot all oranges

    // Directions array for 4 adjacent cells (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Step 1: Initialize the queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                ++freshCount;
            }
        }
    }

    // Step 2: Perform BFS to rot adjacent fresh oranges
    while (!q.empty() && freshCount > 0) {
        ++minutes; // Increment time for each level of BFS
        int size = q.size(); // Process all rotten oranges at the current time step

        for (int i = 0; i < size; ++i) {
            auto [row, col] = q.front();
            q.pop();

            // Traverse in all 4 directions
            for (auto dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                // Check boundaries and whether the cell contains a fresh orange
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2; // Rot the fresh orange
                    q.push({newRow, newCol}); // Add it to the queue
                    --freshCount;             // Decrease fresh orange count
                }
            }
        }
    }

    // If there are still fresh oranges left, return -1; otherwise, return minutes
    return freshCount == 0 ? minutes : -1;
}

int main() {
    // Example input grid
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // BFS solution
    int result = bfsRottenOranges(grid);
    cout << "Minimum Time to Rot All Oranges (BFS): " << result << endl;

    return 0;
}
