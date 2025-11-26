class Solution {
public:
    int mod = 1000000007;
    int Solve(int i, int j, vector<vector<int>>& grid, int k, int pathSum,
              vector<vector<vector<int>>>& dp) {
        if (i < 0 or i >= grid.size() or j < 0 || j >= grid[0].size())
            return 0;
        if (dp[i][j][pathSum % k] != -1)
            return dp[i][j][pathSum % k];
        if (i == grid.size() - 1 and j == grid[0].size() - 1) {
            pathSum += grid[i][j];
            if (pathSum % k == 0) {
                return 1;
            }
            return 0;
        }
        int down = Solve(i + 1, j, grid, k, pathSum + grid[i][j], dp) % mod;
        int right = Solve(i, j + 1, grid, k, pathSum + grid[i][j], dp) % mod;
        return dp[i][j][pathSum % k] = ((down + right) % mod);
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, -1)));
        int ans = Solve(0, 0, grid, k, 0, dp);
        return ans % mod;
    }
};