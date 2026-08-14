// Last updated: 14/08/2026, 15:35:45
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int>ans;
        vector<int> finalAns;
        vector<int> ansCount(101,0);
        for(auto it:nums){
            
            for(int i=0;i<nums.size();i++){
                if(ansCount[it]<1){
                    if(nums[i]<it){
                        ans[it]++;
                        }
                }
                else{
                    break;
                }
            }
            ansCount[it]++;
            finalAns.push_back(ans[it]);
            
        }
        return finalAns;
    }
};