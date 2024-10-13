class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        int min_row = row, max_row = 0;
        int min_col = col, max_col = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    min_row = std::min(min_row, i + 1);
                    max_row = std::max(max_row, i + 1);

                    min_col = std::min(min_col, j + 1);
                    max_col = std::max(max_col, j + 1);
                }
            }
        }

        if (max_row == 0 and min_col == 0) {
            return 0;
        }

        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }
};