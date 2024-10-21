class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = (int)s.size();
        int res = 0;
        for (int i = 0; i < (1 << n); i++) {
            set<string> se;
            string p = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    p += s[j];
                } else {
                    if ((int)p.size() == 0) {
                        continue;
                    }
                    se.insert(p);
                    p = s[j];
                }
            }
            if ((int)p.size() > 0) {
                se.insert(p);
            }
            res = max(res, (int)se.size());
        }
        return res;
    }
};