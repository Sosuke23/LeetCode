class Solution {
public:
    long long maxNumber(long long n) {
        long long res = 0;
        for (int i = 54; i >= 0; i--) {
            if ((1LL << i) & n) { // set
                for (int j = i - 1; j >= 0; j--) {
                    res += (1LL << j);
                }
                int k = 0;
                while (res > n) {
                    res -= (1LL << k);
                    k++;
                }
                return res;
            }
        }
        return -1;
    }
};