// Last updated: 14/08/2026, 15:34:56
class Solution {
public:
    int maximumLengthSubstring(string s) {
        ///sliding growing window?

        unordered_map<char, int> freq;

        int l=0, ans=0;

        for(int r=0; r<s.size();r++){
            freq[s[r]]++;
            while(freq[s[r]]>2){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};