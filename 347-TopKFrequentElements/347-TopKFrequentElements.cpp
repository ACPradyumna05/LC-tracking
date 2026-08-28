// Last updated: 29/08/2026, 03:07:48
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto const& [num,cnt]: freq){
            pq.push({cnt, num});        
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};