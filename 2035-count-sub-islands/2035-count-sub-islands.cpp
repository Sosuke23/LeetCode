class Solution {
public:

    bool f(int i, int j, std::vector<std::vector<int>> &grid2, std::vector<std::vector<int>> &grid1) {
        if (i < 0 or j < 0 or i >= (int)grid2.size() or j >= (int)grid2[0].size() or grid2[i][j] == 0) {
            return 1;
        }

        int res = 1;
        grid2[i][j] = 0;
        res &= f(i + 1, j, grid2, grid1);
        res &= f(i - 1, j, grid2, grid1);
        res &= f(i, j + 1, grid2, grid1);
        res &= f(i, j - 1, grid2, grid1);
        return res & grid1[i][j];
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        for (int i = 0; i < (int)grid2.size(); i++) {
            for (int j = 0; j < (int)grid2[0].size(); j++) {
                if (grid2[i][j] == 1 and grid1[i][j] == 1) {
                    if (f(i, j, grid2, grid1)) {
                        res += 1;
                    }
                }
            }
        }    
        return res;
    }
};