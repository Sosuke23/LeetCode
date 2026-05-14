class Solution {
public:
    int sumOfBlocks(int n) {
        const int MOD = 1e9 + 7;
        int a = 1, res = 0;
        for (int i = 1; i <= n; i++) {
            long long p = 1;
            for (int j = 1; j <= i; j++) {
                (p *= a) %= MOD;
                a++;
            }
            (res += p) %= MOD;
        }
        return res;
    }
};