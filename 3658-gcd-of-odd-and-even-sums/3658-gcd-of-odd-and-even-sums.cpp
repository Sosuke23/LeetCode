class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 0, evn = 0;
        n *= 2;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                evn += i;
            } else {
                odd += i;
            }
        }

        std::cout << odd << " " << evn << '\n';

        int res = std::gcd(evn, odd);
        return res;
    }
};