class Solution {
    int rows, cols;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(const vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (dp[r][c] != 0) {
            return dp[r][c];
        }

        int maxPath = 1; 
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
                maxPath = max(maxPath, 1 + dfs(matrix, nr, nc, dp));
            }
        }

        dp[r][c] = maxPath;
        return maxPath;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        int globalMax = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                globalMax = max(globalMax, dfs(matrix, r, c, dp));
            }
        }

        return globalMax;
    }
};