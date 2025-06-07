class Solution {
public:
    string clearStars(string s) {
        vector<int> pos[26];
        vector<int> vis((int)s.size());

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != '*') {
                pos[s[i] - 'a'].push_back(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!pos[j].empty()) {
                        vis[pos[j].back()] = 1;
                        pos[j].pop_back();
                        break;
                    }
                }
                vis[i] = 1;
            }
        }
        string res = "";
        for (int i = 0; i < (int)s.size(); i++) {
            if (!vis[i]) {
                res += s[i];
            }
        }
        return res;
    }
};