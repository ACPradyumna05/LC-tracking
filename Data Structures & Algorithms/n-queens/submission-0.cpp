class Solution {
    vector<bool> cols;
    vector<bool> diag1; 
    vector<bool> diag2;

    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + (n - 1); 
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, board, result);

            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        cols.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);

        backtrack(0, n, board, result);
        return result;
    }
};