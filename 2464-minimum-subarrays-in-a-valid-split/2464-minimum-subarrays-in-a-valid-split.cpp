class Solution {
public:
    int validSubarraySplit(vector<int>& nums) {
        int n = (int)nums.size();
        const int MAX = 1e9;
        std::vector<int> dp(n + 1, MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (std::__gcd(nums[i - 1], nums[j - 1]) > 1) {
                    dp[i] = std::min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] == MAX ? -1 : dp[n];
    }
};