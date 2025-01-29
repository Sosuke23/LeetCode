class Solution {
public:
    struct DSU {
        int n, cc;
        vector<int> p, sz;

        DSU(int _n) : n(_n), cc(_n) {
            p = vector<int> (n);
            iota(begin(p), end(p), 0);
            sz = vector<int> (n, 1);
        }

        inline int get(int x) {
            if (x == p[x]) {
                return x;
            }
            return p[x] = get(p[x]);
        }

        inline bool unite(int x, int y) {
            x = get(x);
            y = get(y);

            if (x == y) {
                return false;
            }

            sz[y] += sz[x];
            p[x] = y;
            cc--;
            return true;
        }

        inline bool same(int x, int y) {
            return (get(x) == get(y));
        }

        inline int size(int x) {
            return sz[get(x)];
        }

        inline bool root(int x) {
            return (x == get(x));
        }

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();
        DSU dsu(n);
        for (vector<int> e : edges) {
            if (!dsu.unite(e[0] - 1, e[1] - 1)) {
                return {e[0], e[1]};
            }
        }
        return {};
    }
};