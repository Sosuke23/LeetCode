class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        std::unordered_map<std::string, std::string> mp;
        for (std::vector<std::string> r : replacements) {
            mp[r[0]] = r[1];
        }

        bool ok = true;
        std::string res = "";
        while (ok) {
            ok = false;
            res = "";
            for (auto x : text) {
                if (x == '%') {
                    continue;
                } else if (x >= 'A' and x <= 'Z') {
                    res += mp[std::string(1, x)];
                } else {
                    res += x;
                }
            }

            if (count(begin(res), end(res), '%')) {
                ok = true;
            }
            text = res;
        }
        return res;
    }
};