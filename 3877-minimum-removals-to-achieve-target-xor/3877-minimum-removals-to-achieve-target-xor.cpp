class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        std::unordered_map<int, int> dp;
        dp[0] = 0;

        for (int x : nums) {
            target ^= x;
            std::vector<std::pair<int, int>> new_dp(begin(dp), end(dp));
            for (auto [a, b] : new_dp) {
                int next_a = a ^ x;
                int curr_b = dp.count(next_a) ? dp[next_a] : 41;
                dp[next_a] = std::min(curr_b, b + 1);
            }
        }

        return dp.count(target) ? dp[target] : -1;
    }
};