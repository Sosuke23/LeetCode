class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {

        std::vector<std::vector<std::string>> res;
        int n = (int)s1.size();
        std::string s = "", t = "";
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                s += s1[i];
                t += s2[i];
            } else {
                if (!s.empty()) {
                    res.push_back({s, t});
                }
                s = "";
                t = "";
            }
        }

        if (!s.empty()) {
            res.push_back({s, t});
        }
        return res;
    }
};