class Solution {
    int robLinear(const vector<int>& nums, int start, int end) {
        int robPrev2 = 0; 
        int robPrev1 = 0; 
        for (int i = start; i <= end; i++) {
            int current = max(robPrev1, nums[i] + robPrev2);
            robPrev2 = robPrev1;
            robPrev1 = current;
        }

        return robPrev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int maxExcludingLast = robLinear(nums, 0, n - 2);

        int maxExcludingFirst = robLinear(nums, 1, n - 1);

        return max(maxExcludingLast, maxExcludingFirst);
    }
};