class Solution {
    const int M = 1000000007;

    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
    
public:
    int subsequencePairCount(std::vector<int>& nums) {
        int mx = *std::max_element(nums.begin(), nums.end());
        std::vector<std::vector<int>> dp(mx + 1, std::vector<int>(mx + 1));
        dp[0][0] = 1;
        for (auto x : nums) {
            std::vector<std::vector<int>> new_dp = dp;
            for (int j = 0; j <= mx; ++j) {
                for (int k = 0; k <= mx; ++k) {
                    if (dp[j][k]) {
                        add(new_dp[gcd(j, x)][k], dp[j][k]);
                        add(new_dp[j][gcd(k, x)], dp[j][k]);
                    }
                }
            }
            dp = new_dp;
        }
        int res = 0;
        for (int i = 1; i <= mx; ++i) {
            add(res, dp[i][i]);
        }
        return res;
    }
};