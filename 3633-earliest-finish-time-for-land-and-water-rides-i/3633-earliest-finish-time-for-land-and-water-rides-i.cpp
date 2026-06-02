class Solution {
public:
    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int res = INT_MAX;

        int n = (int)a.size();
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, a[i] + b[i]);
        }
        int m = c.size();

        for (int i = 0; i < m; i++) {
            res = min(res, d[i] + max(mn, c[i]));
        }

        mn = INT_MAX;
        for (int i = 0; i < m; i++) {
            mn = min(mn, c[i] + d[i]);
        }

        for (int i = 0; i < n; i++) {
            res = min(res, b[i] + max(mn, a[i]));
        }

        return res;
    }
};