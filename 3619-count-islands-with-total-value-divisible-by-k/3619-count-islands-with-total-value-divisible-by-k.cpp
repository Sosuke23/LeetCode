class Solution {
public:
    long long sum = 0;
    void solve(int i, int j, int row, int col,
               std::vector<std::vector<int>>& used, int k,
               std::vector<std::vector<int>>& grid) {
        if (i < 0 or j < 0 or i >= row or j >= col or used[i][j] or
            grid[i][j] == 0) {
            return;
        }

        used[i][j] = 1;
        sum += grid[i][j];
        solve(i - 1, j, row, col, used, k, grid);
        solve(i + 1, j, row, col, used, k, grid);
        solve(i, j - 1, row, col, used, k, grid);
        solve(i, j + 1, row, col, used, k, grid);
    }
    int countIslands(vector<vector<int>>& grid, int k) {

        int row = (int)grid.size();
        int col = (int)grid[0].size();
        int res = 0;
        std::vector<std::vector<int>> used(row, std::vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!used[i][j]) {
                    sum = 0;
                    solve(i, j, row, col, used, k, grid);
                    res += (sum != 0 and sum % k == 0);
                }
            }
        }
        return res;
    }
};