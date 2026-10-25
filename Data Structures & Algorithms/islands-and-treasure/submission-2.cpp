class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

        const int INF=2147483647;

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            for(auto& [dr,dc]:directions){
                int nr=r+dr;
                int nc=c+dc;

                if(nr>=0 && nr<m && nc>=0 && nc<n &&grid[nr][nc]==INF){
                    grid[nr][nc]=grid[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
