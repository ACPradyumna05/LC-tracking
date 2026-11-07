class Solution {

    int countFromCenter(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int totalPalindromes = 0;

        for (int i = 0; i < s.length(); i++) {
            totalPalindromes += countFromCenter(s, i, i);

            totalPalindromes += countFromCenter(s, i, i + 1);
        }

        return totalPalindromes;
    }
};