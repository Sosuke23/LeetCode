class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long res = 0;
        if (n > k) {
            res += 1LL * (n - k) * k;
        }
        if (m > k) {
            res += 1LL * (m - k) * k;
        }

        return res;
    }
};