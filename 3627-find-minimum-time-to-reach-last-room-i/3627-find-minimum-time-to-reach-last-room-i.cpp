class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
        int dis[n][m];
        memset(dis, -1, sizeof(dis));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto arr = pq.top();
            pq.pop();
            int i = arr[1], j = arr[2];
            if (dis[i][j] >= 0) {
                continue;
            } 
            dis[i][j] = arr[0];
            for (int k = 0; k < 4; k++) {
                int ii = i + dir[k][0], jj = j + dir[k][1];
                if (ii < 0 || jj < 0 || ii >= n || jj >= m || dis[ii][jj] >= 0) {
                    continue;
                } 
                int val = max(moveTime[ii][jj] + 1, dis[i][j] + 1);
                pq.push({val, ii, jj});
            }
        }
        return dis[n - 1][m - 1];
    }
};