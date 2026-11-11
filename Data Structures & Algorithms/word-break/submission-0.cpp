class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            if (start == n) return true;

            for (int end = start + 1; end <= n; end++) {
                if (!visited[end] && dict.count(s.substr(start, end - start))) {
                    visited[end] = true;
                    q.push(end);
                }
            }
        }

        return false;
    }
};