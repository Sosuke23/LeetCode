#define sz(x) (int)x.size()
class Solution {
public:
    int mod = 1000000007;
    int countKReducibleNumbers(string s, int k) {
        vector<int> dp(sz(s) + 1, 0);
        dp[0] = 1;
        vector<int> freq(sz(s) + 1, 0);
        for (int i = sz(s) - 1; i >= 0; i--) {
            if (s[i] == '1') {
                int cnt = 0;
                for (int j = 0; j < i; j++) {
                    cnt += s[j] == '1';
                }
                for (int j = 0; j + cnt <= sz(s); j++) {
                    freq[cnt + j] += dp[j];
                    if (freq[cnt + j] >= mod) {
                        freq[cnt + j] -= mod;
                    }
                }
            }
            for (int j = sz(s); j > 0; j--) {
                dp[j] += dp[j - 1];
                if (dp[j] >= mod) {
                    dp[j] -= mod;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= sz(s); i++) {
            int cur = i;
            for (int j = 0; j < k - 1; j++) {
                int nxt = 0;
                while (cur) {
                    nxt += cur & 1;
                    cur >>= 1;
                }
                cur = nxt;
            }
            if (cur == 1) {
                res += freq[i];
                if (res >= mod) {
                    res -= mod;
                }
            }
        }
        return res;
    }
};