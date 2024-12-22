template <typename T, typename CMP = less<T>> struct SparseTable {
    constexpr static CMP cmp{};
    static T min(const T& a, const T& b) { return (cmp(a, b) ? a : b); }
    static int lg(int x) { return 31 - __builtin_clz(x); }

    vector<vector<T>> st;

    SparseTable(const vector<T>& a) {
        int n = a.size();
        int b = lg(n);

        st.push_back(a);
        for (int i = 1; i <= b; i++) {
            int m = n - (1 << i) + 1;
            vector<T> b(m);
            for (int j = 0; j < m; j++) {
                b[j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
            st.push_back(b);
        }
    }

    T query(int l, int r) {
        int i = lg(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& hs, vector<vector<int>>& qs) {
        int n = hs.size();
        SparseTable<int, greater<int>> st(hs);

        vector<int> res;
        for (auto q : qs) {
            int a = q[0], b = q[1];
            if (a > b)
                swap(a, b);

            if (a == b || hs[a] < hs[b]) {
                res.push_back(b);
                continue;
            }

            int maxh = max(hs[a], hs[b]);

            int ans = n;
            int l = b + 1, r = n - 1;
            int mid;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (st.query(b + 1, mid) > maxh) {
                    ans = min(ans, mid);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            if (ans == n) {
                res.push_back(-1);
            } else {
                res.push_back(ans);
            }
        }
        return res;
    }
};