const int N = 110;
const int inf = 0x3f3f3f3f;
int dp[N][N];
class Solution {
public:
    int minArraySum(vector<int>& a, int k, int op1, int op2) {
        int f = 0, g = 0;
        for (int i = 0; i <= op1; ++i) {
            for (int j = 0; j <= op2; ++j) {
                dp[i][j] = inf;
            }
        }
        int w;
        dp[0][0] = 0;
        for (int v : a) {
            for (int i = op1; i >= 0; --i) {
                for (int j = op2; j >= 0; --j) {
                    dp[i][j] = min(inf, dp[i][j] + v);
                    if (i > 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + (v + 1) / 2);
                    }
                    if (j > 0 && v >= k) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + v - k);
                    }
                    if (i > 0 && j > 0) {
                        w = (v + 1) / 2;
                        if (w >= k) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + w - k);
                        }
                        if (v >= k) {
                            dp[i][j] = min(dp[i][j],
                                           dp[i - 1][j - 1] + (v - k + 1) / 2);
                        }
                    }
                }
            }
        }
        int res = inf;
        for (int i = 0; i <= op1; ++i) {
            for (int j = 0; j <= op2; ++j) {
                res = min(res, dp[i][j]);
            }
        }
        return res;
    }
};