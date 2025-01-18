class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void Dfs(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &Dp, int cost, queue<pair<int, int>> &Q) {
        if (r < 0 or c < 0 or r >= (int)grid.size() or c >= (int)grid[0].size() or Dp[r][c] != INT_MAX) {
            return;
        }
        Dp[r][c] = cost;
        Q.push({r, c});
        int ndir = grid[r][c] - 1;
        Dfs(grid, r + dir[ndir][0], c + dir[ndir][1], Dp, cost, Q);
    }

    int minCost(vector<vector<int>>& grid) {
        int row = (int)grid.size(), col = (int)grid[0].size();
        int cost = 0;
        vector<vector<int>> Dp(row, vector<int> (col, INT_MAX));
        queue<pair<int, int>> Q;
        Dfs(grid, 0, 0, Dp, cost, Q);
        while (!Q.empty()) {
            cost += 1;
            int sz = (int)Q.size();
            for (int i = 0; i < sz; i++) {
                auto f = Q.front();
                int r = f.first, c = f.second;
                Q.pop();
                for (int j = 0; j < 4; j++) {
                    Dfs(grid, r + dir[j][0], c + dir[j][1], Dp, cost, Q);
                }
            }
        }
        return Dp[row - 1][col - 1];
    }
};