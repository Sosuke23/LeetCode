class Solution {
public:
    int countWinningSequences(string s) {
        int n = s.size();

        auto win = [&](int x, char ch) {
            int y;
            if (ch == 'F') {
                y = 0;
            } else if (ch == 'W') {
                y = 1;
            } else {
                y = 2;
            }

            if (x == y)
                return 0;
            if ((x == 0 && y == 2) || (x == 1 && y == 0) ||
                (x == 2 && y == 1)) {
                return 1;
            }
            return -1;
        };

        const int mod = 1e9 + 7;

        vector<vector<int>> dp(2 * n + 1, vector<int>(3, 0));
        for (int i = 0; i < 3; i++) {
            dp[n + win(i, s[0])][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            vector<vector<int>> ndp(2 * n + 1, vector<int>(3, 0));
            for (int j = 0; j <= 2 * n; j++) {
                for (int k = 0; k < 3; k++) {
                    if (dp[j][k] != 0) {
                        for (int l = 0; l < 3; l++)
                            if (l != k) {
                                ndp[j + win(l, s[i])][l] += dp[j][k];
                                ndp[j + win(l, s[i])][l] %= mod;
                            }
                    }
                }
            }

            dp = ndp;
        }

        int res = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            for (int j = 0; j < 3; j++) {
                res += dp[i][j];
                res %= mod;
            }
        }

        return res;
    }
};