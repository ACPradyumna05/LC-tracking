// Last updated: 14/08/2026, 15:35:41
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m=mat[0].size();
        long long ans = 0;

        vector<int> height(m,0);


        for(int i=0;i<n;i++){
            //Update Heights
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    height[j]=0;
                }
                else{
                    height[j]++;
                }


            }
            ans += countRow(height);
        }
        return ans;
    }

    int countRow(vector<int>& height){
        int m = height.size();
        vector<int> sum(m,0);
        stack<int> st;
        int res=0;

        for(int j=0;j<m;j++){
            while(!st.empty() && height[st.top()] >= height[j]){
                st.pop();
            }

            if(!st.empty()){
                int prev = st.top();
                sum[j] = sum[prev] + height[j]*(j-prev);
            }

            else{
                sum[j] = height[j]*(j+1);
            }

            st.push(j);
            res += sum[j];
        }
        return res;
    }
};