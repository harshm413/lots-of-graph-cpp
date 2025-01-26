#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS function for Flood Fill
void dfsFloodFill(int row, int col, vector<vector<int>>& image, int newColor, int startColor) {
    int rows = image.size();
    int cols = image[0].size();

    // Base case: check boundaries and whether the current cell is the same as the start color
    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != startColor) {
        return;
    }

    // Change the current cell's color to the new color
    image[row][col] = newColor;

    // Directions array: {row_change, col_change}
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Visit all 4 neighbors
    for (auto dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;
        dfsFloodFill(newRow, newCol, image, newColor, startColor);
    }
}

// BFS function for Flood Fill
void bfsFloodFill(int sr, int sc, vector<vector<int>>& image, int newColor) {
    int rows = image.size();
    int cols = image[0].size();
    int startColor = image[sr][sc];

    // If the starting cell is already the new color, no need to process
    if (startColor == newColor) return;

    // Initialize a queue for BFS
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor; // Change the starting cell's color

    // Directions array: {row_change, col_change}
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Process the queue
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        // Explore neighbors
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            // Check boundaries and whether the cell has the same start color
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && image[newRow][newCol] == startColor) {
                q.push({newRow, newCol});
                image[newRow][newCol] = newColor; // Change the cell's color
            }
        }
    }
}

// Function to perform Flood Fill using DFS
vector<vector<int>> floodFillDFS(vector<vector<int>> image, int sr, int sc, int newColor) {
    int startColor = image[sr][sc];
    if (startColor != newColor) {
        dfsFloodFill(sr, sc, image, newColor, startColor);
    }
    return image;
}

// Function to perform Flood Fill using BFS
vector<vector<int>> floodFillBFS(vector<vector<int>> image, int sr, int sc, int newColor) {
    bfsFloodFill(sr, sc, image, newColor);
    return image;
}

int main() {
    // Example input image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, newColor = 2;

    // DFS solution
    vector<vector<int>> resultDFS = floodFillDFS(image, sr, sc, newColor);
    cout << "Flood Fill (DFS):" << endl;
    for (const auto& row : resultDFS) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    // Reset the image for BFS
    image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    // BFS solution
    vector<vector<int>> resultBFS = floodFillBFS(image, sr, sc, newColor);
    cout << "Flood Fill (BFS):" << endl;
    for (const auto& row : resultBFS) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
