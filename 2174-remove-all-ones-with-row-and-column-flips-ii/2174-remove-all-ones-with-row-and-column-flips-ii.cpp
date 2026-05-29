class Solution {
public:
    int removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < m; k++) {
                        grid[k][j] <<= 1;
                    }
                    for (int k = 0; k < n; k++) {
                        grid[i][k] <<= 1;
                    }
                    res = min(res, 1 + removeOnes(grid));
                    for (int k = 0; k < m; k++) {
                        grid[k][j] >>= 1;
                    }
                    for (int k = 0; k < n; k++) {
                        grid[i][k] >>= 1;
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};