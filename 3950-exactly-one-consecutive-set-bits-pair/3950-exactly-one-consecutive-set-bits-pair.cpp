class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0;
        for (int i = 25; i > 0; i--) {
            if ((n & (1 << i)) and (n & (1 << (i - 1)))) {
                cnt++;
            }
        }
        return (cnt == 1);
    }
};