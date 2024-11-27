class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> e[n];
        for (int i = 1; i < n; i++) {
            e[i - 1].push_back(i);
        } 

        auto bfs = [&]() {
            int dis[n];
            memset(dis, -1, sizeof(dis));
            queue<int> q;
            q.push(0); dis[0] = 0;
            while (!q.empty()) {
                int sn = q.front(); q.pop();
                for (int fn : e[sn]) if (dis[fn] == -1) {
                    q.push(fn); dis[fn] = dis[sn] + 1;
                }
            }
            return dis[n - 1];
        };

        vector<int> res;
        for (auto &qry : queries) {
            e[qry[0]].push_back(qry[1]);
            res.push_back(bfs());
        }
        return res;
    }
};