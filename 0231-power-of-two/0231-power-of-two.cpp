class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        long p = n;
        return !(p & (p - 1));
    }
};