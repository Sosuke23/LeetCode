class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }

        vector<vector<int>> dp(4, vector<int>(n + 1, 0));
        vector<vector<int>> index(4, vector<int>(n + 1, 0));

        for (int j = 1; j <= 3; ++j) {
            for (int i = j * k; i <= n; ++i) {
                int current = sum[i] - sum[i - k] + dp[j - 1][i - k];
                if (current > dp[j][i - 1]) {
                    dp[j][i] = current;
                    index[j][i] = i - k;
                } else {
                    dp[j][i] = dp[j][i - 1];
                    index[j][i] = index[j][i - 1];
                }
            }
        }

        vector<int> result(3);
        int idx = n;
        for (int j = 3; j > 0; --j) {
            result[j - 1] = index[j][idx];
            idx = result[j - 1];
        }

        return result;
    }
};