// Last updated: 14/08/2026, 15:36:27
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int> result;
        unordered_map<int,vector<int>> diagonals;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                diagonals[i+j].push_back(mat[i][j]);

            }
        }
        for(int d=0;d<row+col-1;++d){
            if(d%2==0){
                reverse(diagonals[d].begin(), diagonals[d].end());

            }
            result.insert(result.end(),diagonals[d].begin(),diagonals[d].end());
        }
        return result;
        
    }
};