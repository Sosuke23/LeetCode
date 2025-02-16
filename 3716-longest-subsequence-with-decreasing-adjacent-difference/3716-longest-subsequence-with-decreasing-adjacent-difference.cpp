class Solution {
public:
    int n, a[10005], lst[305], dp[10005][305], pd[10005][305];
    int longestSubsequence(vector<int>& nums) {
        n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            a[i + 1] = nums[i];
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][300] = 1;
            for (int j = 0; j <= 300; ++j) {
                if (lst[j] == 0) {
                    continue;                   
                }
                int now = abs(j - a[i]);
                dp[i][now] = std::max(dp[i][now], pd[lst[j]][now] + 1);
            }
            pd[i][300] = dp[i][300];
            for (int j = 299; j >= 0; --j) {
                pd[i][j] = std::max(dp[i][j], pd[i][j + 1]);
            }
            lst[a[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= 300; ++j) {
                res = std::max(res, dp[i][j]);
            }
        }
        return res;
    }
};