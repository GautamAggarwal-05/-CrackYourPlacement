class Solution {
public:
    bool isValid(const vector<vector<int>>& board, int i, int j) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
    }
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int count = 0;
                if (isValid(board, i - 1, j - 1) && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3)) {
                    count++;
                }
                if (isValid(board, i - 1, j) && (board[i - 1][j] == 1 || board[i - 1][j] == 3)) {
                    count++;
                }
                if (isValid(board, i - 1, j + 1) && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3)) {
                    count++;
                }
                if (isValid(board, i, j + 1) && (board[i][j + 1] == 1 || board[i][j + 1] == 3)) {
                    count++;
                }
                if (isValid(board, i + 1, j + 1) && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 3)) {
                    count++;
                }
                if (isValid(board, i + 1, j) && (board[i + 1][j] == 1 || board[i + 1][j] == 3)) {
                    count++;
                }
                if (isValid(board, i + 1, j - 1) && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 3)) {
                    count++;
                }
                if (isValid(board, i, j - 1) && (board[i][j - 1] == 1 || board[i][j - 1] == 3)) {
                    count++;
                }
                if (board[i][j] == 1 && count < 2) {
                    board[i][j] = 3;
                } else if (board[i][j] == 1 && (count == 2 || count == 3)) {
                    board[i][j] = 1;
                } else if (board[i][j] == 1 && count > 3) {
                    board[i][j] = 3;
                } else if (board[i][j] == 0 && count == 3) {
                    board[i][j] = 4;
                }
                cout << board[i][j] << endl;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 3) {
                    board[i][j] = 0;
                } else if (board[i][j] == 4) {
                    board[i][j] = 1;
                }
            }
        }
    }
};