class Solution {
    long long f[105][105][105];
    int d[105][105];

public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size(), m = factory.size(), i, j, k;
        memset(f, 127, sizeof(f));
        f[0][0][0] = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                d[i][j] = abs(robot[i] - factory[j][0]);
            }
        }
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= m; j++) {
                if (j < m) {
                    f[i][j + 1][0] = min(f[i][j + 1][0], *min_element(f[i][j], f[i][j] + 105));
                }
                if (i < n && j < m) {
                    for (k = 0; k < factory[j][1]; k++) {
                        f[i + 1][j][k + 1] = min(f[i + 1][j][k + 1], f[i][j][k] + d[i][j]);
                    }
                }
            }
        }
        return f[n][m][0];
    }
};