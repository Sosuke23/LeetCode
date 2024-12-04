class Solution {
public:
    int smallestNumber(int n) {
        int res = 0;
        bool ok = false;
        for (int i = 10; i >= 0; i--) {
            if (n & (1 << i)) {
                ok = true;
            }

            if (ok) {
                res += (1 << i);
            }
        }
        return res;
    }
};