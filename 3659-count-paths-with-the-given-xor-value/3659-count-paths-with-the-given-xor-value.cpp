class Solution {
public:
const int MOD = 1e9 + 7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) { 
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        vector dp(n, vector (m, vector<int> (16)));
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int b = 0; b < 16; b++) {
                    if (dp[i][j][b]) {
                        if (i + 1 < n) {
                            (dp[i + 1][j][b ^ grid[i + 1][j]] += dp[i][j][b]) %= MOD;
                        }
                        if (j + 1 < m) {
                            (dp[i][j + 1][b ^ grid[i][j + 1]] += dp[i][j][b]) %= MOD;
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1][k];
    }
};