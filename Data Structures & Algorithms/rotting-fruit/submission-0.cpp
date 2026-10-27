class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int sz = q.size();
            bool rottedAny = false;

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        freshCount--;
                        rottedAny = true;
                        q.push({nr, nc});
                    }
                }
            }

            if (rottedAny) {
                minutes++;
            }
        }

        return (freshCount == 0) ? minutes : -1;
    }
};