class Solution {
public:
    vector<vector<int>> dp, g;
    const int dx[4] = {-1, 0, 1}, dy[4] = {1, 1, 1};

    int f(int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= dp.size() || nj >= dp[0].size() ||g[ni][nj] <= g[i][j]) {
                continue;
            }
            res = max(res, 1 + f(ni, nj));
        }
        return dp[i][j] = res;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        g = grid;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, f(i, 0));
        }
        return res;
    }
};