// Last updated: 14/08/2026, 15:35:43
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0;
        int curr=0;

        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
            }
            else{
                ans=max(ans,prev+curr);
                prev=curr;
                curr=0;
            }
            ans=max(ans,prev+curr);
        }
        if(ans==nums.size()){
            ans--;
        }
        return ans;

    }
};