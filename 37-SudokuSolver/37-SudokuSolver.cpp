// Last updated: 14/08/2026, 15:36:58
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == ch || board[i][col] == ch)
                return false;
        }
        int boxRow = 3 * (row / 3), boxCol = 3 * (col / 3);
        for (int i = boxRow; i < boxRow + 3; ++i) {
            for (int j = boxCol; j < boxCol + 3; ++j) {
                if (board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if (solve(board))
                                return true;
                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no valid digit found
                }
            }
        }
        return true; // board is completely filled
    }

};