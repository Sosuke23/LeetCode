class Solution {
public:
#define i23 long long
    long long minEnd(int n, int x) {
        i23 res = x;
        n--;
        for (int i = 0; n; i++) {
            if (!((res >> i) & 1)) {
                if (n & 1) {
                    res ^= (1LL << i);
                }
                n /= 2;
            }
        }
        return res;
    }
};