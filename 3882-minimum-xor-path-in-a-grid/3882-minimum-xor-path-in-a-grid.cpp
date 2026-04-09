class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        std::vector<std::vector<std::vector<int>>> dp (row + 1, std::vector<std::vector<int>> (col + 1, std::vector<int> (1024, 0)));
        
        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < 1024; k++) {
                    if (dp[i][j][k]) {
                        if (i + 1 < row) {
                            dp[i + 1][j][k ^ grid[i + 1][j]] = 1;
                        }
                        if (j + 1 < col) {
                            dp[i][j + 1][k ^ grid[i][j + 1]] = 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 1024; i++) {
            if (dp[row - 1][col - 1][i]) {
                return i;
            }
        }

        return -1;
    }
};