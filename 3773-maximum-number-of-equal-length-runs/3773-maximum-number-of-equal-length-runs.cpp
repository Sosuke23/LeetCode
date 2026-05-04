class Solution {
public:
    int maxSameLengthRuns(string s) {
        s += "#";
        std::unordered_map<int, int> mp;
        std::string t = "";
        
        for (int i = 0; i < (int)s.size(); i++) {
            if (!t.empty() && t.back() == s[i]) {
                t.push_back(s[i]);
            } else if (t.empty()) {
                t.push_back(s[i]);
            } else {
                mp[(int)t.size()]++;
                t = "";
                t.push_back(s[i]);
            }
        }

        int res = 0;
        for (auto [_ ,val] : mp) {
            res = std::max(res, val);
        }
        return res;
    }
};