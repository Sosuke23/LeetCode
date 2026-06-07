class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int res {0};
        for (int i = 1; i <= 200; i++) {
            if (std::abs(n - i) <= k and (n & i) == 0) {
                res += i;
            }
        }
        return res;
    }
};