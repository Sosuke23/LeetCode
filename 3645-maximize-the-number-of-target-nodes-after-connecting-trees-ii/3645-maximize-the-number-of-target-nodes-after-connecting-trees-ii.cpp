class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, N = edges2.size() + 1;
        vector<int> e[n], E[N];
        for (auto &edge : edges1) {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2) {
            E[edge[0]].push_back(edge[1]);
            E[edge[1]].push_back(edge[0]);
        }

        int a[n], c[2] = {0};
        int A[N], C[2] = {0};
        auto dfs = [&](auto &&self, int sn, int fa, int col, int *a, int *c, vector<int> *e) -> void {
            a[sn] = col; c[col]++;
            for (int fn : e[sn]) {
                if (fn != fa) {
                    self(self, fn, sn, col ^ 1, a, c, e);
                }
            }
        };
        dfs(dfs, 0, -1, 0, a, c, e);
        dfs(dfs, 0, -1, 0, A, C, E);

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = c[a[i]];
        } 
        if (N == 1) {
            return res;
        } 
        int mx = max(C[0], C[1]);
        for (int i = 0; i < n; i++) {
            res[i] += mx;
        }
        return res;
    }
};