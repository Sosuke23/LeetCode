class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = (int)s.size();
        vector<int> bit(n + 4);
        auto update = [&] (int l, int val) {
            int i = l + 1;
            while (i <= n + 1) {
                bit[i] += val;
                i += i & (-i);
            }
        };

        auto Query = [&] (int l) {
            int ret = 0;
            int i = l + 1;
            while (i > 0) {
                ret += bit[i];
                i -= i & (-i);
            }
            return ret;
        };

        string res = "";
        for (auto &v : shifts) {
            if (v[2]) {
                update(v[0], 1);
                update(v[1] + 1, -1);
            }
            else {
                update(v[0], -1);
                update(v[1] + 1, 1);
            }
        }

        for (int i = 0; i < n; i++) {
            char c = 'a' + (26 + (s[i] - 'a') + Query(i) % 26) % 26;
            res += c;
        }
        return res;
    }
};