class Solution {
public:

    void f(int i, int j, int row, int col, std::vector<int> &pos, std::vector<std::vector<int>> &land) {
        if (i == row or j == col or land[i][j] == 0) {
            return;
        }
        land[i][j] = 0;
        if (i + j > pos[2] + pos[3]) {
            pos[2] = i;
            pos[3] = j;
        }
        f(i + 1, j, row, col, pos, land);
        f(i, j + 1, row, col, pos, land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = (int)land.size();
        int col = (int)land[0].size();
        std::vector<std::vector<int>> res;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    std::vector<int> pos = {i, j, i, j};
                    f(i, j, row, col, pos, land);
                    res.push_back(pos);
                }
            }
        }
        
        return res;
    }
};