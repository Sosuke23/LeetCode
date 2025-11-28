class Solution {
public:
    int res = -1;
    long Dfs(int u, vector<int> adj[], vector<int> & val, int p, int k) {
        long Sum = val[u];
        for (auto v : adj[u]) {
            if (v == p) {
                continue;
            }
            Sum += Dfs(v, adj, val, u, k);
        }
        if (Sum % k == 0) {
            res += 1;
            Sum = 0;
        }
        return Sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> G[n + 4];
        for (int i = 0; i < (int)edges.size(); i++) {
            G[edges[i][0]].push_back(edges[i][1]);
            G[edges[i][1]].push_back(edges[i][0]);
        }
        long A = Dfs(0, G, values, -1, k);
        res += ((A % k) == 0);
        return res;
    }
};