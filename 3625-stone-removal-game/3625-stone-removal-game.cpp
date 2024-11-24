class Solution {
public:
    bool canAliceWin(int n) {
        int to = 10;
        int a = 0;
        while (n >= to) {
            n -= to;
            to--;
            a ^= 1;
        }
        return a;
    }
};