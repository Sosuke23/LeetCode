class Solution {
public:
    int maximumLength(string s) {
        map<char, vector<int>> mp;
        map<string, int> Cnt;
        s += '$';
        int n = (int)s.size();
        string t = "";
        for (int i = 0; i < n; i++) {
            if (t.empty()) {
                t += s[i];
                continue;
            }

            if (s[i] == t.back()) {
                t += s[i];
            }
            else {
                mp[t[0]].push_back((int)t.size());
                t = "";
                t += s[i];
            }
        }


        int res = 0;
        for (auto &[key, val] : mp) {
            sort(rbegin(val), rend(val));
            if ((int)val.size() >= 1) {
                res = max(res, (int)val[0] - 2);
            }
            if ((int)val.size() >= 2) {
                res = max(res, min(val[0] - 1, val[1]));
            }
            if ((int)val.size() >= 3) {
                res = max(res, val[2]);
            }
        }
        return (res == 0 ? -1 : res);
    }
};