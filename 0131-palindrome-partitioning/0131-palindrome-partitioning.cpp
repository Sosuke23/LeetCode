class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> res;
        int n = (int)s.size();

        auto palin = [&] (std::string a) {
            int k = (int)a.size();
            for (int i = 0; i < k / 2; i++) {
                if (a[i] != a[k - i - 1]) {
                    return false;
                }
            }
            return true;
        };

        auto check = [&] (std::vector<std::string> p) {
            int len = 0;
            bool ok = true;
            for (int i = 0; i < (int)p.size(); i++) {
                if (palin(p[i])) {
                    len += (int)p[i].size();
                    continue;
                } else {
                    return false;
                }
            }

            return (len == n);
        };

        for (int i = 0; i < (1 << n); i++) {
            int prev = 0;
            std::vector<std::string> curr;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curr.push_back(s.substr(prev, j - prev + 1));
                    prev = j + 1;
                }
            }
            if (check(curr)) {
                res.push_back(curr);
            }
        }
        return res;
    }
};