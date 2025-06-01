class Solution {
public:
    long long distributeCandies(int n, int limit) {

        if (n > 3 * limit) {
            return 0;
        }
        
        auto f = [&] (int a) {
            return 1LL * a * (a - 1) / 2;
        };

        long long res = f(n + 2);
        if (n > limit) {
            res -= 3 * f(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            res += 3 * f(n - 2 * limit);
        }
        return res;
    }
};