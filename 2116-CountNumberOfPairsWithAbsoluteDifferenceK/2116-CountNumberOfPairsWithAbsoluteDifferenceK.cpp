// Last updated: 14/08/2026, 15:35:16
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(abs(nums[i]-nums[j])==k){
                    count++;
                }
            }
        }
        return count;
    }
};