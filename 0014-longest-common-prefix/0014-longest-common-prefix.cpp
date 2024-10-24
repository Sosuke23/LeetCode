class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if ((int)strs.size() == 1) {
            return strs[0];
        }

        string res = "";
        int mn = 1000;
        for (auto x : strs) {
            mn = std::min(mn, (int)x.size());
        }
        for (int i = 0; i < mn; i++) {
            bool ok = true;
            for (int j = 1; j < (int)strs.size(); j++) {
                if (strs[j][i] == strs[j - 1][i]) {
                    continue;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res += strs[0][i];
            } else {
                break;
            }
        }
        return res;
    }
};