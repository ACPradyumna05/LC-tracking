// Last updated: 29/08/2026, 21:02:28
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> prefix{{0,1}};
       int result =0;
       int runner =0;
       for(int num:nums){
        runner+=num;
        result+=prefix[runner-k];
        ++prefix[runner];
       }
       return result;
    }
};