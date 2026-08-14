// Last updated: 14/08/2026, 15:34:42
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        auto processDiagonal = [&](int r, int c, bool ascending) {
            vector<int> diag;
            int i = r, j = c;

            // collect
            while (i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }

            // sort
            if (ascending)
                sort(diag.begin(), diag.end());
            else
                sort(diag.begin(), diag.end(), greater<int>());

            // put back
            i = r, j = c;
            int k = 0;
            while (i < n && j < n) {
                grid[i][j] = diag[k++];
                i++; j++;
            }
        };

        for (int r = 0; r < n; r++) {
            processDiagonal(r, 0, false);
        }

        for (int c = 1; c < n; c++) {
            processDiagonal(0, c, true);
        }

        return grid;
    }
};