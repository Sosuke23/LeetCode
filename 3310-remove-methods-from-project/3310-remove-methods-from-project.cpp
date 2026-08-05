class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n), radj(n);
        for (auto v : invocations) {
            int x = v[0], y = v[1];
            adj[x].push_back(y);
            radj[y].push_back(x);
        }

        vector<int> mark(n);
        queue<int> qu;
        qu.push(k);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            mark[u] = 1;
            for (int v : adj[u]) {
                if (!mark[v]) {
                    mark[v] = 1;
                    qu.push(v);
                }
            }
        }

        bool good = true;
        for (int i = 0; i < n; ++i)
            for (int u : adj[i]) {
                if (!mark[i] and mark[u]) {
                    good = false;
                }
            }

        if (!good) {
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                v.push_back(i);
            }
            return v;
        }
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (!mark[i]) {
                v.push_back(i);
            }
        }
        return v;
    }
};