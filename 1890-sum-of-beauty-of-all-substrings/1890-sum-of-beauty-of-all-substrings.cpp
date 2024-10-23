class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        int n = (int)s.size();
        for (int i = 0; i + 1 < n; i++) {
            array<int, 26> cnt;
            for (int k = 0; k < 26; k++) {
                cnt[k] = 0;
            }
            cnt[s[i] - 'a'] += 1;
            for (int j = i + 1; j < n; j++) {
                cnt[s[j] - 'a'] += 1;
                int mn = INT_MAX, mx = 0;
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] > 0) {
                        mn = min(mn, cnt[k]);
                        mx = max(mx, cnt[k]);
                    }
                }
                res += (mx - mn);
            }
        }
        return res;
    }
};