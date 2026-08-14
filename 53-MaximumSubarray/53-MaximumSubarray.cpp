// Last updated: 14/08/2026, 15:36:50
class Solution {
public:
    int maxCrossingSum(vector<int> &arr, int l, int m, int h) {
  
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return (leftSum + rightSum);
}

int MaxSum(vector<int> &arr, int l, int h) {
  
    if (l > h)
        return INT_MIN;

    if (l == h)
        return arr[l];

    int m = l + (h - l) / 2;

    int leftSum = MaxSum(arr, l, m);
    int rightSum = MaxSum(arr, m + 1, h);
    int crossSum = maxCrossingSum(arr, l, m, h);

    if (leftSum >= rightSum && leftSum >= crossSum)
        return leftSum;
    else if (rightSum >= leftSum && rightSum >= crossSum)
        return rightSum;
    else
        return crossSum;
}

int maxSubArray(vector<int> &arr) {
    int n = arr.size();
    return MaxSum(arr, 0, n - 1);
}
};
