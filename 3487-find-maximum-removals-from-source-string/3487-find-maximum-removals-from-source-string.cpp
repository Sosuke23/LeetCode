class Solution {
public:
    int maxRemovals(string s, string p, vector<int>& ti) {
        int n = s.size(), m = p.size();
        vector<bool> v(n, false);

        for (int idx : ti) {
            v[idx] = true;
        }
        vector<int> t(m + 1, INT_MAX / 2);
        t[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = min(i, m - 1); j >= 0; --j) {
                if (s[i] == p[j]) {
                    int cost = t[j] + v[i];
                    t[j + 1] = min(t[j + 1], cost);
                }
            }
        }
        int min_used = t[m];
        return ti.size() - min_used;
    }
};