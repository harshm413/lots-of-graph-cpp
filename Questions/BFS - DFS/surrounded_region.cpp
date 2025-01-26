#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        
        // BFS function to mark safe 'O's
        auto bfs = [&](int r, int c) {
            queue<pair<int, int>> q;
            q.push({r, c});
            board[r][c] = '#'; // Mark as visited (safe)

            while (!q.empty()) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (auto& dir : directions) {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == 'O') {
                        q.push({newRow, newCol});
                        board[newRow][newCol] = '#'; // Mark as safe
                    }
                }
            }
        };

        // Step 1: Traverse the boundary and mark safe 'O's
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') bfs(i, 0);
            if (board[i][m - 1] == 'O') bfs(i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') bfs(0, j);
            if (board[n - 1][j] == 'O') bfs(n - 1, j);
        }

        // Step 2: Flip all 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // Surrounded region
                else if (board[i][j] == '#') board[i][j] = 'O'; // Safe region
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution solution;
    solution.solve(board);

    // Print the modified board
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
