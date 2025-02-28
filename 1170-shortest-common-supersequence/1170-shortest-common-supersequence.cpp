class Solution {
public:
    string lcs(string a, string b) {
        int n = (int)a.size(), m = (int)b.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = n, j = m;
        std::string res = "";
        while (i and j) {
            if (a[i - 1] == b[j - 1]) {
                res = a[i - 1] + res;
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    res = a[i - 1] + res;
                    i--;
                } else {
                    res = b[j - 1] + res;
                    j--;
                }
            }
        }
        while (i) {
            res = a[i - 1] + res;
            i--;
        }
        while (j) {
            res = b[j - 1] + res;
            j--;
        }
        return res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string res = lcs(str1, str2);
        return res;
    }
};