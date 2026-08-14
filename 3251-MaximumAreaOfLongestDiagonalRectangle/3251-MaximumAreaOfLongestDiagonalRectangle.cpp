// Last updated: 14/08/2026, 15:35:00
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double ans=INT_MIN;
        double prev=INT_MIN;
        int curr=0;
        for(int i=0;i<dimensions.size();i++){
            ans=max(ans,sqrt(dimensions[i][1]*dimensions[i][1]+dimensions[i][0]*dimensions[i][0]));
            if(prev!=ans){
                prev=ans;
                curr=i;
            }
            else if(sqrt(dimensions[i][1]*dimensions[i][1]+dimensions[i][0]*dimensions[i][0])==prev){
                //two entries have same length of diagonal
                curr=dimensions[i][1]*dimensions[i][0]>dimensions[curr][1]*dimensions[curr][0]?i:curr;
            }
        }
        return (dimensions[curr][0]*dimensions[curr][1]);
    }
};