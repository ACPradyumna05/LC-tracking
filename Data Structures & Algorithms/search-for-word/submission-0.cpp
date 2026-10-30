class Solution {
public:
    int m,n;
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        if (index == word.size()) {
            return true;
        }

        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        board[r][c] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        if (word.size() > m * n) return false;

        vector<int> boardCount(128, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boardCount[board[i][j]]++;
            }
        }
        for (char ch : word) {
            if (--boardCount[ch] < 0) return false;
        }

        if (count(word.begin(), word.end(), word.front()) > 
            count(word.begin(), word.end(), word.back())) {
            reverse(word.begin(), word.end());
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
