class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<pair<int, int>> adj[n];
        for (vector<int> e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        auto Dijkstra = [&] (int start) {
            priority_queue<pair<int, int>> pq;
            vector<int> dist(n, INT_MAX);
            vector<int> vis(n, 0);
            dist[start] = 0;
            pq.push({0, start});
            while (!pq.empty()) {
                int a = pq.top().second;
                pq.pop();
                if (vis[a]) {
                    continue;
                }
                vis[a] = 1;
                for (auto u : adj[a]) {
                    int b = u.first;
                    int w = u.second;
                    if (dist[a] + w < dist[b]) {
                        dist[b] = dist[a] + w;
                        pq.push({-dist[b], b});
                    }
                }
            }
            return dist;
        };

        int mn = INT_MAX, res = 0;
        for (int i = 0; i < n; i++) {
            auto d = Dijkstra(i);
            int cnt = 0;
            for (auto x : d) {
                cnt += (x <= k);
            }
            if (cnt == mn) {
                res = i;
                continue;
            }
            if (cnt < mn) {
                mn = cnt;
                res = i;
            }
        }
        return res;
    }
};