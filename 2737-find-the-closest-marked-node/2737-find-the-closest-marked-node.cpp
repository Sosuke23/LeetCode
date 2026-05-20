class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int from, vector<int>& marked) {
        std::vector<std::pair<int, int>> adj[n];
        std::vector<bool> used(n, 0);
        std::vector<long long> dis(n, INT_MAX);
        int res = INT_MAX;

        for (std::vector<int> e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        std::priority_queue<pair<int, int>> PQ;

        dis[from] = 0; 
        PQ.push({0, from});
        while (!PQ.empty()) {
            int a = PQ.top().second;
            PQ.pop();

            if (used[a]) {
                continue;
            }
            used[a] = true;
            for (auto u : adj[a]) {
                int b = u.first;
                int w = u.second;
                if (dis[a] + w < dis[b]) {
                    dis[b] = dis[a] + w;
                    PQ.push({-dis[b], b});
                }
            }
        }
        
        for (int node : marked) {
            if (dis[node] <= INT_MAX) {
                res = std::min(res, (int)dis[node]);
            }
        }

        return (res >= INT_MAX ? -1 : res);
    }
};