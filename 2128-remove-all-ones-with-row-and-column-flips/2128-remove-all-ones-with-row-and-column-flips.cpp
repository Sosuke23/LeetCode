class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int row = (int)grid.size();
        int col = (int)grid[0].size();

        for (int i = 0; i < col; i++) {
            if (grid[0][i] == 1) {
                for (int j = 0; j < row; j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }

        for (int i = 0; i < row; i++) {
            int a = 0;
            for (int j = 0; j < col; j++) {
                a += grid[i][j];
            }

            if (a > 0 and a < col) {
                return false;
            }
        }
        return true;
    }
};