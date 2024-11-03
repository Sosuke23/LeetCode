class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
        int dis[n][m][2];
        memset(dis, -1, sizeof(dis));
        typedef array<int, 4> a4;
        priority_queue<a4, vector<a4>, greater<a4>> pq;
        pq.push({0, 0, 0, 0});
        while (!pq.empty()) {
            auto arr = pq.top();
            pq.pop();
            int i = arr[1], j = arr[2], t = arr[3];
            if (dis[i][j][t] >= 0) {
                continue;
            }
            dis[i][j][t] = arr[0];
            for (int k = 0; k < 4; k++) {
                int ii = i + dir[k][0], jj = j + dir[k][1], tt = t ^ 1;
                if (ii < 0 || jj < 0 || ii >= n || jj >= m || dis[ii][jj][tt] >= 0)  {
                    continue;
                }
                int step = (t & 1 ? 2 : 1);
                int val = max(moveTime[ii][jj], dis[i][j][t]) + step;
                pq.push({val, ii, jj, tt});
            }
        }
        int res = 2e9;
        for (int i = 0; i < 2; i++) {
            if (dis[n - 1][m - 1][i] >= 0) {
                res = min(res, dis[n - 1][m - 1][i]);
            } 
        }
        return res;
    }
};