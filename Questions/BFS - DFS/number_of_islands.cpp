#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS function using a directions array
void dfs(int i, int j, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Directions array: {row_change, col_change}
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Mark the current cell as visited
    grid[i][j] = '0';

    // Traverse in all 4 directions
    for (auto dir : directions) {
        int newRow = i + dir.first;
        int newCol = j + dir.second;

        // Check boundaries and whether the cell is land
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == '1') {
            dfs(newRow, newCol, grid);
        }
    }
}

// BFS function using a queue
void bfs(int i, int j, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Directions array: {row_change, col_change}
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Initialize a queue for BFS
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0'; // Mark as visited

    while (!q.empty()) {
        auto [currRow, currCol] = q.front();
        q.pop();

        // Explore neighbors
        for (auto dir : directions) {
            int newRow = currRow + dir.first;
            int newCol = currCol + dir.second;

            // Check boundaries and whether the cell is land
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == '1') {
                q.push({newRow, newCol});
                grid[newRow][newCol] = '0'; // Mark as visited
            }
        }
    }
}

// Function to count the number of islands using DFS
int numIslandsDFS(vector<vector<char>> grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0;

    // Traverse the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If we find a '1' (land), it's the start of a new island
            if (grid[i][j] == '1') {
                ++islandCount;   // Increment the island count
                dfs(i, j, grid); // Perform DFS to mark the entire island
            }
        }
    }

    return islandCount;
}

// Function to count the number of islands using BFS
int numIslandsBFS(vector<vector<char>> grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0;

    // Traverse the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If we find a '1' (land), it's the start of a new island
            if (grid[i][j] == '1') {
                ++islandCount;   // Increment the island count
                bfs(i, j, grid); // Perform BFS to mark the entire island
            }
        }
    }

    return islandCount;
}

int main() {
    // Example input: 2D grid
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Number of islands using DFS
    int dfsResult = numIslandsDFS(grid);
    cout << "Number of Islands (DFS): " << dfsResult << endl;

    // Reset the grid for BFS
    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Number of islands using BFS
    int bfsResult = numIslandsBFS(grid);
    cout << "Number of Islands (BFS): " << bfsResult << endl;

    return 0;
}
