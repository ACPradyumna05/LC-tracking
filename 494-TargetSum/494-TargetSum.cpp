// Last updated: 14/08/2026, 15:36:30
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int SumVec = accumulate(nums.begin(), nums.end(), 0);
        if(SumVec<abs(target) || (SumVec + target)%2 != 0){
            return 0;
        } 

        int DPsize = (SumVec + target)/2;
        vector<int> dp(DPsize + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j=DPsize; j>=num; --j) {
                dp[j]+= dp[j-num];
            }
        }
        return dp[DPsize];
    }
};