// Last updated: 14/08/2026, 15:36:05
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
    int m = grid[0].size(); 

    // delrow and delcol are used to traverse in
    // up,right,bottom and left respectively.
    int delrow[] = { -1, 0, 1, 0 };
    int delcol[] = { 0, 1, 0, -1 };

    // visited matrix to keep track of the visited cell.
    int vis[n][m];

    // queue stores rowIndex,colIndex and time taken to rot
    // respectively.
    queue<pair<pair<int, int>, int> > q;

    // counter to keep track of fresh cells.
    int cntfresh = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          
            // already rotten hence 0 time to rot.
            // and mark as visited
            if (grid[i][j] == 2) {
                q.push({ { i, j }, 0});
                vis[i][j] = 2; 
            }
            else {
                vis[i][j] = 0; // unvisited
            }
          
            // Increment count for fresh oranges.
            if (grid[i][j] == 1)
                cntfresh++; 
        }
    }
    int cnt = 0, tm = 0;
    while (!q.empty()) {
      
        int row = q.front().first.first; 
        int col = q.front().first.second; 
        int t = q.front().second; 
      
        q.pop();

        tm = max(tm, t);

        // checking for adjacent nodes in 4 directions.
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // checking the validity of a node and also
            // vis[nrow][ncol] !=2
            if (nrow >= 0 && nrow < n && ncol >= 0
                && ncol < m && grid[nrow][ncol] == 1
                && vis[nrow][ncol] != 2) {
              
                // adj orange is rotten
                vis[nrow][ncol] = 2;
              
                // incrementing time for that orange by 1
                q.push({ { nrow, ncol }, t + 1 }); 
                cnt++;
            }
        }
    }

    return (cnt == cntfresh) ? tm : -1;
    }
};