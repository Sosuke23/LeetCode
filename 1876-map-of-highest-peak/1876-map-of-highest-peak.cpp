class Solution {
public:
    int dirx[4] = {-1, 1, 0, 0};
    int diry[4] = {0, 0, 1, -1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = (int)isWater.size();
        int col = (int)isWater[0].size();

        vector<vector<int>> res(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>> Q;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    Q.push({i,j});
                }
            }
        }

        while(! Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dirx[i];
                int ny = y + diry[i];

                if (nx >=0 and nx < row and ny >= 0 and ny < col and res[nx][ny] > 1 + res[x][y]) {
                    Q.push({nx,ny});
                    res[nx][ny] = 1 + res[x][y];
                }
            }
        }

        return res;
    }
};