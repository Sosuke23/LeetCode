class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        auto bfs = [&] (int x, vector<vector<int>> &adj) {
            int n = (int)adj.size();
            vector<int> dis(n, -1);
            dis[x] = 0;
            queue<int> q;
            q.push(x);
            while (!q.empty()) {
                int s = q.front();
                q.pop();
                for (auto u : adj[s]) {
                    if (dis[u] == -1) {
                        dis[u] = dis[s] + 1;
                        q.push(u);
                    }
                }
            }
            return dis;
        };

        auto f = [&] (vector<vector<int>> &edges) {
            int n = (int)edges.size() + 1;
            vector<int> res(n);
            vector<vector<int>> adj(n);
            for (vector<int> &e : edges) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }

            vector<int> d1 = bfs(0, adj);
            int a = max_element(begin(d1), end(d1)) - begin(d1);

            vector<int> d2 = bfs(a, adj);
            int b = max_element(begin(d2), end(d2)) - begin(d2);

            vector<int> d3 = bfs(b, adj);

            for (int i = 0; i < n; i++) {
                res[i] = max(d2[i], d3[i]);
            }

            return res;
        };

        vector<int> A = f(edges1);
        vector<int> B = f(edges2);

        int mn_a = *min_element(begin(A), end(A));
        int mx_a = *max_element(begin(A), end(A));

        int mn_b = *min_element(begin(B), end(B));
        int mx_b = *max_element(begin(B), end(B));

        return max({mx_a, mx_b, mn_a + mn_b + 1});
    }
};