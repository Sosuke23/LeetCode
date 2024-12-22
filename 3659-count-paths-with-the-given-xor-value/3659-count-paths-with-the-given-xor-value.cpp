class Solution {
public:
const int MOD = 1e9 + 7;
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) { 
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<unordered_map<int, int>>> dp(m, vector<unordered_map<int, int>>(n));

        function<int(int, int, int)> dfs = [&](int i, int j, int curr_xor) {
            if (i == m - 1 && j == n - 1) {
                return (curr_xor ^ grid[i][j]) == k ? 1 : 0;
            }

            if (i >= m || j >= n) {
                return 0;
            }

            if (dp[i][j].count(curr_xor)) {
                return dp[i][j][curr_xor];
            }

            int res = 0;
            res = (res + dfs(i, j + 1, curr_xor ^ grid[i][j])) % MOD;
            res = (res + dfs(i + 1, j, curr_xor ^ grid[i][j])) % MOD;

            return dp[i][j][curr_xor] = res;
        };

        return dfs(0, 0, 0);
    }
};