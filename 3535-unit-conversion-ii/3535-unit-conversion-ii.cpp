#define i23 long long

class Solution {
public:
    const int MOD = 1e9 + 7;
    i23 mod(i23 a, i23 b) {
        i23 res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    i23 inv_mod(i23 a) {
        return mod(a, MOD - 2);
    }
    vector<int> queryConversions(vector<vector<int>>& conversions, vector<vector<int>>& queries) {
        int n = (int)conversions.size() + 1;
        std::vector<std::tuple<i23, i23, i23>> adj[n];

        for (std::vector<int> c : conversions) {
            i23 inv = inv_mod(c[2]);
            adj[c[0]].push_back({c[1], c[2], inv});
            adj[c[1]].push_back({c[0], inv, c[2]});
        }


        std::vector<i23> dis(n), inv_dis(n);
        std::vector<i23> used(n, 0);
        dis[0] = 1;
        inv_dis[0] = 1;

        std::function<void(int)> Dfs = [&] (int node) {
            used[node] = 1;
            for (auto u : adj[node]) {
                i23 neighbour, da, db;
                tie(neighbour, da, db) = u;
                if (used[neighbour]) {
                    continue;
                }

                dis[neighbour] = dis[node] * da % MOD;
                inv_dis[neighbour] = inv_dis[node] * db % MOD;
                Dfs(neighbour);
            }
        };        
        Dfs(0);

        std::vector<int> res((int)queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            res[i] = (int)dis[queries[i][1]] * inv_dis[queries[i][0]] % MOD;
        }
        return res;



    }
};