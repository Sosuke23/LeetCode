class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = (int)s.size();
        int res = 0;
        for (int i = 0; i <= n - k; i++) {
            std::array<int, 26> cnt {0};
            bool ok = true;
            cnt[s[i] - 'a'] = 1;
            for (int j = i + 1; j <= i + k - 1; j++) {
                cnt[s[j] - 'a']++;
                if (cnt[s[j] - 'a'] > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                res++;
            }
        }
        return res;
    }
};