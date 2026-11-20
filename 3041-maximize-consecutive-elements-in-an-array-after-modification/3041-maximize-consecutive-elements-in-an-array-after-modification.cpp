class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        map<int, int> Dp;
        int res = 0;
        sort(begin(nums), end(nums));
        for (auto x : nums) {
            if (Dp.find(x) != Dp.end()) {
                Dp[x + 1] = Dp[x] + 1;
            } else {
                Dp[x + 1] = 1;
            }
            
            if (Dp.find(x - 1) != Dp.end()) {
                Dp[x] = Dp[x - 1] + 1;
            } else {
                Dp[x] = 1;
            }
        }
        for (auto &[_, v] : Dp) {
            res = max(res, v);
        }
        return res;
    }
};