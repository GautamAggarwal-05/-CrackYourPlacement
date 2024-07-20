class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& grid, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }

        if (grid[i][j] == 'X' || grid[i][j] == 'V') {
            return true;
        }

        grid[i][j] = 'V';

        bool up = dfs(i - 1, j, grid, m, n);
        bool down = dfs(i + 1, j, grid, m, n);
        bool left = dfs(i, j - 1, grid, m, n);
        bool right = dfs(i, j + 1, grid, m, n);

        return up && down && left && right;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    // If the region is surrounded, mark all 'O' as 'X'
                    if (dfs(i, j, board, m, n)) {
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                if (board[x][y] == 'V') {
                                    board[x][y] = 'X';
                                }
                            }
                        }
                    } else {
                        // If not surrounded, revert all 'V' back to 'O'
                        for (int x = 0; x < m; x++) {
                            for (int y = 0; y < n; y++) {
                                if (board[x][y] == 'V') {
                                    board[x][y] = 'O';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};
