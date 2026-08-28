// Last updated: 29/08/2026, 03:08:10
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_set<char> visited;
        for(int right=0;right<s.length();right++){
            while(visited.contains(s[right])){
                visited.erase(s[left]);
                left++;
            }
            visited.insert(s[right]);
            ans=max(ans,right-left+1);

        }
        return ans;
    }
};