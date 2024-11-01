class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int n = (int)s.size();
        string t = "";
        t += s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                t += s[i];
            } else {
                if ((int)t.size() > 2) {
                    res += t[0];
                    res += t[0];
                } else {
                    res += t;
                }
                t = s[i];
            }
        }
        if (!t.empty()) {
            if ((int)t.size() > 2) {
                res += t[0];
                res += t[0];
            } else {
                res += t;
            }
        }
        return res;
    }
};