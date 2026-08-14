// Last updated: 14/08/2026, 15:34:40
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int startRow = miniRow(0, 0, grid.size(), grid[0].size(), grid);
        int startCol = miniCol(0, 0, grid.size(), grid[0].size(), grid);
        int endRow   = maxiRow(0, 0, grid.size(), grid[0].size(), grid);
        int endCol   = maxiCol(0, 0, grid.size(), grid[0].size(), grid);
        int ans = INT_MAX;

        // Vertical split
        for (int i = startCol + 1; i < endCol; i++) {
            //i skips left border otherwise cut doesn't happen
            //i=first slash
            for (int j = i + 1; j <= endCol; j++) {
                //j skips i otherwise cut doesn't happen
                //j=second slash
                int area1 = minimumArea(startRow, endRow + 1, startCol, i, grid);
                int area2 = minimumArea(startRow, endRow + 1, i, j, grid);
                int area3 = minimumArea(startRow, endRow + 1, j, endCol + 1, grid);
                if (area1 != INT_MAX && area2 != INT_MAX && area3 != INT_MAX)
                    ans = min(ans, area1 + area2 + area3);
            }
        }

        // Horizontal splits
        for (int i = startRow+1; i < endRow; i++) {
            for (int j = i+1; j <= endRow; j++) {
                int area1 = minimumArea(startRow, i, startCol, endCol+1, grid);
                int area2 = minimumArea(i, j, startCol, endCol+1, grid);
                int area3 = minimumArea(j, endRow+1, startCol, endCol+1, grid);
                if (area1 != INT_MAX && area2 != INT_MAX && area3 != INT_MAX) {
                    ans = min(ans, area1 + area2 + area3);
                }
            }
        }

        // Mixed partitions: vertical first, then horizontal
        for (int cut = startCol + 1; cut <= endCol; cut++) {
            // Left side split horizontally
            for (int i = startRow + 1; i <= endRow; i++) {  
                int area1 = minimumArea(startRow, endRow + 1, cut, endCol + 1, grid); 
                int area2 = minimumArea(startRow, i, startCol, cut, grid);            
                int area3 = minimumArea(i, endRow + 1, startCol, cut, grid);          
                if (area1 != INT_MAX && area2 != INT_MAX && area3 != INT_MAX)
                    ans = min(ans, area1 + area2 + area3);
            }
            // Right side split horizontally
            for (int i = startRow + 1; i <= endRow; i++) { 
                int area1 = minimumArea(startRow, endRow + 1, startCol, cut, grid);   
                int area2 = minimumArea(startRow, i, cut, endCol + 1, grid);          
                int area3 = minimumArea(i, endRow + 1, cut, endCol + 1, grid);        
                if (area1 != INT_MAX && area2 != INT_MAX && area3 != INT_MAX)
                    ans = min(ans, area1 + area2 + area3);
            }
        }

        // Mixed partitions: horizontal first, then vertical
        for (int cut = startRow + 1; cut <= endRow; cut++) {
            // Top side split vertically
            for (int j = startCol + 1; j <= endCol; j++) { 
                int area1 = minimumArea(cut, endRow + 1, startCol, endCol + 1, grid); 
                int area2 = minimumArea(startRow, cut, startCol, j, grid);            
                int area3 = minimumArea(startRow, cut, j, endCol + 1, grid);         
                if (area1 != INT_MAX && area2 != INT_MAX && area3 != INT_MAX)
                    ans = min(ans, area1 + area2 + area3);
            }
            // Bottom side split vertically
            for (int j = startCol + 1; j <= endCol; j++) { 
                int area1 = minimumArea(startRow, cut, startCol, endCol + 1, grid);  
                int area2 = minimumArea(cut, endRow + 1, startCol, j, grid);          
                int area3 = minimumArea(cut, endRow + 1, j, endCol + 1, grid);        
                if (area1 != INT_MAX && area2 != INT_MAX && area3 != INT_MAX)
                    ans = min(ans, area1 + area2 + area3);
            }
        }

        return ans;
    }

    int minimumArea(int firstRow, int lastRow, int firstCol, int lastCol, vector<vector<int>>& grid) {
        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;
        for (int i = firstRow; i < lastRow; i++) {
            for (int j = firstCol; j < lastCol; j++) {
                if (grid[i][j] == 1) {
                    maxCol = max(maxCol, j);
                    maxRow = max(maxRow, i);
                    minRow = min(minRow, i);
                    minCol = min(minCol, j);
                }
            }
        }
        if (minRow == INT_MAX) return INT_MAX; // no 1’s
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int maxiRow(int startRow, int startCol, int endRow, int endCol, vector<vector<int>>& grid) {
        int maxRow = INT_MIN;
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) maxRow = max(maxRow, i);
            }
        }
        return (maxRow == INT_MIN ? 0 : maxRow);
    }

    int maxiCol(int startRow, int startCol, int endRow, int endCol, vector<vector<int>>& grid) {
        int maxCol = INT_MIN;
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) maxCol = max(maxCol, j);
            }
        }
        return (maxCol == INT_MIN ? 0 : maxCol);
    }

    int miniRow(int startRow, int startCol, int endRow, int endCol, vector<vector<int>>& grid) {
        int minRow = INT_MAX;
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) minRow = min(minRow, i);
            }
        }
        return (minRow == INT_MAX ? 0 : minRow);
    }

    int miniCol(int startRow, int startCol, int endRow, int endCol, vector<vector<int>>& grid) {
        int minCol = INT_MAX;
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) minCol = min(minCol, j);
            }
        }
        return (minCol == INT_MAX ? 0 : minCol);
    }
};