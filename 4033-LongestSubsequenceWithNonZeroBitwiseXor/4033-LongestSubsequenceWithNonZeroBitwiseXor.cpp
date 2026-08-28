// Last updated: 29/08/2026, 03:06:34
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool hasNonZero=false;
        for(int x:nums){
            xr ^= x;
            if(xr!=0){
                hasNonZero=true;
            }
        }
        if(xr!=0){
            return nums.size();
        }
        else if (hasNonZero){
            return nums.size()-1;
        }
        return 0;
    }
};