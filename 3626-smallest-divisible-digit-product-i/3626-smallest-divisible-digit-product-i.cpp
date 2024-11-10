class Solution {
public:
    int smallestNumber(int n, int t) {
        while (1) {
            int product = 1;
            int x = n;
            while (x) {
                product *= x % 10;
                x /= 10;
            }
            if (product % t == 0) {
                return n;
            }
            ++n;
        }
        return n;
    }
};