class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        std::vector<int> adj[n];
        for (std::vector<int> edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        std::vector<long long> vis(n, LLONG_MAX);

        std::function<long long(int)> Dfs = [&] (int node) {
            
            if (adj[node].size() == 0) {
                return (long long)baseTime[node];
            }

            if (vis[node] != LLONG_MAX) {
                return vis[node];
            }

            long long earliest = LLONG_MAX, latest = 0;
            for (auto neighbour : adj[node]) {
                long long time = Dfs(neighbour);
                earliest = std::min(earliest, time);
                latest = std::max(latest, time);
            }

            long long own_duration = baseTime[node] + (latest - earliest);
            long long finish_time = latest + own_duration;
            vis[node] = finish_time;
            return finish_time;
        };

        long long res = Dfs(0);
        return res;
    }
};