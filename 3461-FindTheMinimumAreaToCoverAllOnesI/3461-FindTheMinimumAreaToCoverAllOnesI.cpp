// Last updated: 14/08/2026, 15:34:37
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow=INT_MAX,maxRow=INT_MIN;
        int minCol=INT_MAX, maxCol=INT_MIN;
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    maxCol=max(maxCol,j);
                    maxRow=max(maxRow,i);
                    minRow=min(minRow,i);
                    minCol=min(minCol,j);
                }
            }
        }
        return (maxRow-minRow+1)*(maxCol-minCol+1);
    }
};