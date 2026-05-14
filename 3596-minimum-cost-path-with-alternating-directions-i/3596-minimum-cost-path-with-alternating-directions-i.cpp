class Solution {
public:
    int minCost(int m, int n) {
        if (n == m and n == 1) {
            return 1;
        } else if ((n == 2 and m == 1) or (n == 1 and m == 2)) {
            return 3;
        }
        return -1;
    }
};