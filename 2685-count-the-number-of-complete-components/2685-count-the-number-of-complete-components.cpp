struct DSU {
	vector<int> p, sz;
	void init(int n) { 
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
	int find_set(int v) { 
        return v == p[v] ? v : p[v] = find_set(p[v]);
    }
	bool union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a, sz[a] += sz[b], sz[b] = 0;
		return true;
	}
} d;


class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        d.init(n);
        for (auto v : edges) {
            int a = v[0], b = v[1];
            d.union_sets(a, b);
        }
        vector<int> cnt(n);
        for (auto v : edges) {
            int a = v[0], b = v[1];
            cnt[d.find_set(a)]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) if (d.p[i] == i) {
            int x = d.sz[i];
            if (x * (x - 1) / 2 == cnt[i]) ans++;
        }
        return ans;
    }
};