// Last updated: 29/08/2026, 21:02:24
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<int> warmer;

        for(int i=temperatures.size()-1;i>=0;--i){
            int curr=temperatures[i];
            while(!warmer.empty()&&temperatures[warmer.top()]<=curr){
                warmer.pop();
            }
            if(!warmer.empty()){
                ans[i]=warmer.top()-i;
            }
            warmer.push(i);
        }
        return ans;
    }
};