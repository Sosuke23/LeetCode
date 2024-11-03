class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.size();
        int m = (n + 1) / 2;

        int sm = 0, cnt[10] = {0};
        for (char c : num) {
            sm += c - '0';
            cnt[c - '0']++;
        }
        if (sm & 1) {
            return 0;
        }
        sm /= 2;

        const int MOD = 1e9 + 7;
        auto update = [&](long long& a, long long b) { a = (a + b) % MOD; };

        long long C[n + 1][n + 1];
        memset(C, 0, sizeof(C));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                update(C[i][j], C[i - 1][j - 1] + C[i - 1][j]);
            }
        }

        long long f[11][m + 1][sm + 1];
        memset(f, 0, sizeof(f));
        f[0][0][0] = 1;
        int now = 0;
        for (int i = 1; i <= 10; i++) {
            int x = i - 1;
            now += cnt[x];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= sm; k++) {
                    int rem1 = m - j, rem2 = n - now - rem1;
                    if (rem1 < 0 || rem2 < 0)
                        continue;
                    for (int jj = 0; jj <= cnt[x] && jj <= j && x * jj <= k; jj++) {
                        update(f[i][j][k],
                               f[i - 1][j - jj][k - x * jj] * C[rem1 + jj][jj] %
                                   MOD * C[rem2 + cnt[x] - jj][cnt[x] - jj]);
                    }
                }
            }
        }
        return f[10][m][sm];
    }
};