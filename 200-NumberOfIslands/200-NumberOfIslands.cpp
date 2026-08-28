// Last updated: 29/08/2026, 03:07:57
class Solution {
public:
    void dfs(int r,int c, int rows, int cols, vector<vector<char>>& grid){
        if(r<0 or r>=rows or c<0 or c>=cols or grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        dfs(r,c-1,rows, cols, grid);
        dfs(r-1,c,rows, cols, grid);
        dfs(r+1,c,rows, cols, grid);
        dfs(r,c+1,rows, cols, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        ///dfs
        int rows=grid.size();
        int cols=grid[0].size();
        int islands = 0;
        
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]=='1'){
                    islands++;
                    dfs(r,c,rows, cols, grid);
                }
            }
        }
        return islands;
    }
};