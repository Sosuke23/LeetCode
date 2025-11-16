class Solution {
public:
    int numSub(string s) {
        long long res = 0;
        int n = (int)s.size();
        int mod = 1e9 + 7;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (cnt) {
                    (res += 1LL * cnt * 1LL * (cnt + 1) / 2) %= mod;
                }
                cnt = 0;
            } else {
                cnt++;
            }
        }
        if (cnt) {
            (res += 1LL * cnt * 1LL * (cnt + 1) / 2) %= mod;
        } 
        return res;
    }
};