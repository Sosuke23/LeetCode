class Solution {
public:
    
    int Solve(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 or j < 0 or i >= (int)grid.size() or j >= (int)grid[0].size() or grid[i][j] == 0) {
            return 0;
        }
        int res = grid[i][j];
        grid[i][j] = 0;
        return res + Solve(grid, i, j + 1) + Solve(grid, i, j - 1) + Solve(grid, i - 1, j) + Solve(grid, i + 1, j);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                auto G = grid;
                res = max(res, Solve(G, i, j));
            }
        }
        return res;
    }
};