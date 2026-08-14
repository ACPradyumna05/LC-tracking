// Last updated: 14/08/2026, 15:36:36
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sizeC=coins.size();
        vector<int> dp;
        dp.resize(amount+1,INT_MAX);
        dp[0]=0;
        for(int c=0;c<sizeC;c++){
            int coin=coins[c];
            for(int i=coin;i<=amount;i++){
                if(dp[i-coin]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }

        if(dp[amount]==INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        }
    }
};