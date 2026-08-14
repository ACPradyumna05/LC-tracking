// Last updated: 14/08/2026, 15:35:54
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m=matrix[0].size();
        int ans = 0;

        vector<vector<int>> result(n+1,vector<int>(m+1,0));


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    result[i+1][j+1]=min({result[i][j+1],result[i][j],result[i+1][j]})+1;
                    ans = ans + result[i+1][j+1];
                }
            }

        }
        return ans;
    }
};