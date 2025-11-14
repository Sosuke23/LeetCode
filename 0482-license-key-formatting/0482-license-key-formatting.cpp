class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t = "";
        for (auto x : s) {
            if (x == '-') {
                continue;
            }
            t += toupper(x);
        }
        reverse(t.begin(), t.end());
        string ans = "";
        string a = "";
        for (int i = 0; i < (int)t.size(); i++) {
            if ((i + 1) % k == 0) {
                a += t[i];
                ans += a;
                ans += '-';
                a = "";
            } else {
                a += t[i];
            }
        }
        if ((int)a.size()) {
            ans += a;
        }
        reverse(ans.begin(), ans.end());
        if (ans[0] == '-') {
            ans.erase(ans.begin());
        }
        return ans;
    }
};