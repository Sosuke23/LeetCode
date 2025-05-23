class Solution {
public:
    #define i23 long long 
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int> > Adj(n);
        for(auto &it: edges) {
            int u = it[0], v = it[1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        vector<i23> f[2];
        f[0].assign(n, 0);
        f[1].assign(n, 0);
        
        function<void(int, int)> dfs = [&](int u, int p) {
            f[0][u] = nums[u];
            f[1][u] = nums[u] ^ k;
            for(int v: Adj[u]) {
                if(v == p) {
                    continue;
                }
                dfs(v, u);
                i23 g[2] = {max(f[0][u] + f[0][v], f[1][u] + f[1][v]), max(f[0][u] + f[1][v], f[1][u] + f[0][v])};
                f[0][u] = g[0];
                f[1][u] = g[1];
            }
        };
        dfs(0, -1);
        return f[0][0];
    }
};