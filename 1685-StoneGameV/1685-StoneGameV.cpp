// Last updated: 29/08/2026, 03:07:22
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + stoneValue[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length = length of current subarray
        for (int len = 2; len <= n; ++len) {

            for (int l = 0; l + len - 1 < n; ++l) {

                int r = l + len - 1;

                for (int k = l; k < r; ++k) {

                    int leftSum =
                        prefix[k + 1] - prefix[l];

                    int rightSum =
                        prefix[r + 1] - prefix[k + 1];

                    int candidate;

                    if (leftSum < rightSum) {
                        candidate = leftSum + dp[l][k];
                    }
                    else if (leftSum > rightSum) {
                        candidate = rightSum + dp[k + 1][r];
                    }
                    else {
                        candidate = leftSum +
                            max(dp[l][k], dp[k + 1][r]);
                    }

                    dp[l][r] = max(dp[l][r], candidate);
                }
            }
        }

        return dp[0][n - 1];
    }
};