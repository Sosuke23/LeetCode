class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        map<char, int> mp;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2) % mod;
            if (mp.count(s[i - 1])) {
                dp[i] = (dp[i] - dp[mp[s[i - 1]]] + mod) % mod;
            }
            mp[s[i - 1]] = i - 1;
        }
        return (dp[n] - 1 + mod) % mod;
    }
};