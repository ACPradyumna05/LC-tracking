// Last updated: 14/08/2026, 15:36:45
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        unordered_map<int,int> ansMap;
        vector<int> ans;
        for(auto it:nums){
            map[it]++;
        }
        for(auto it:map){
            if(it.second>nums.size()/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};