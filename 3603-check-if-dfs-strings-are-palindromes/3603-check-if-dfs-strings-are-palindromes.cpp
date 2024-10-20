class Solution {
public:
    int siz[100005], f[100005], g[100005], n, val[100005], pw[100005];
    bool ans[100005];
    std::vector <int> son[100005];
    const int mod = 998244853, base = 41;
    inline int mul(int x, int y){
        return 1ll * x * y % mod;
    }
    inline int add(int x, int y){
        return x + y >= mod ? x + y - mod : x + y;
    }
    inline int minus(int x, int y){
        return x < y ? x - y + mod : x - y;
    }
    void dfs(int x){
        siz[x] = 1;
        for(auto v: son[x]){
            dfs(v);
            siz[x] += siz[v];
        }
        for(int i = 0; i < son[x].size(); ++i){
            int v = son[x][i];
            f[x] = mul(f[x], pw[siz[v]]);
            f[x] = add(f[x], f[v]);
        }
        f[x] = mul(f[x], pw[1]);
        f[x] = add(f[x], val[x]);
        
        g[x] = val[x];
        for(int i = son[x].size() - 1; i >= 0; --i){
            int v = son[x][i];
            g[x] = mul(g[x], pw[siz[v]]);
            g[x] = add(g[x], g[v]);
        }
        if(f[x] == g[x]) ans[x] = true;
        else ans[x] = false;
        return ;
    }
    vector<bool> findAnswer(vector<int>& parent, string s) {
        n = parent.size();
        pw[0] = 1;
        for(int i = 1; i <= n; ++i) pw[i] = mul(pw[i - 1], base);
        for(int i = 0; i < n; ++i){
            val[i] = s[i] - 'a' + 10;
            if(i != 0) son[parent[i]].push_back(i);
        }
        dfs(0);
        std::vector <bool> res; res.resize(n);
        for(int i = 0; i < n; ++i) res[i] = ans[i];
        return res;
    }
};