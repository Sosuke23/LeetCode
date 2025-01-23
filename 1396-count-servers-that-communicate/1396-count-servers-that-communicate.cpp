class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = (int)grid.size();
        int col = (int)grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    bool ok = false;
                    for (int k = i + 1; k < row; k++) {
                        if (grid[k][j] == 1) {
                            vis[k][j] = 1;
                            ok = true;
                        }
                    }

                    for (int k = j + 1; k < col; k++) {
                        if (grid[i][k] == 1) {
                            vis[i][k] = 1;
                            ok = true;
                        }
                    }
                    if (ok) {
                        vis[i][j] = 1;
                    }
                }
            }
        }
        int res = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res += (vis[i][j] == 1);
            }
        }
        return res;
    }
};