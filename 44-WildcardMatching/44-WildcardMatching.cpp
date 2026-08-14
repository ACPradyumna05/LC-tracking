// Last updated: 14/08/2026, 15:36:55
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0;  
        int starIndex = -1, match = 0; 
        
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (j < n && p[j] == '*') {
                starIndex = j;
                match = i;
                j++;
            }
            else if (starIndex != -1) {
                j = starIndex + 1;
                match++;
                i = match;
            }
            else {
                return false;
            }
        }
        
        while (j < n && p[j] == '*') {
            j++;
        }
        
        return j == n;
    }
};
