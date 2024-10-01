class Solution {
public:
    bool solve(int i, int j, int n, int m, vector<vector<char>>& board, string& temp, string& word, vector<vector<int>>& visited) {
        if (temp.length() > word.length()) return false; 
        if (temp == word) return true;
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || board[i][j] != word[temp.length()]) 
            return false;
        visited[i][j] = true;
        temp.push_back(board[i][j]);

        bool up = solve(i - 1, j, n, m, board, temp, word, visited);    // Move up
        bool down = solve(i + 1, j, n, m, board, temp, word, visited);  // Move down
        bool left = solve(i, j - 1, n, m, board, temp, word, visited);  // Move left
        bool right = solve(i, j + 1, n, m, board, temp, word, visited); // Move right

        temp.pop_back();
        visited[i][j] = false;

        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, false));
        string temp = "";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (solve(i, j, n, m, board, temp, word, visited)) {
                    return true; 
                }
            }
        }

        return false;  
    }
};
