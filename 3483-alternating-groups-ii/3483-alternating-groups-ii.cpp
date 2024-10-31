class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = (int)colors.size();
        vector<int> dp(2 * n, 1);
        for (int i = 1; i < 2 * n; i++) {
            if (colors[i % n] != colors[(i - 1) % n]) {
                dp[i % n] = dp[(i - 1) % n] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] >= k or dp[i + n] >= k) {
                res += 1;
            }
        }
        return res;
    }
};