// Last updated: 14/08/2026, 15:35:31
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans=0;
        for(auto num:nums){
            ans+=map[num];
            map[num]++;
        }
        return ans;
    }
};