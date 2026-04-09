class Solution {
public:
    int minCost(int n) {
        if (n == 1) {
            return 0;
        }
        n -= 1;
        int res = n * (n + 1) / 2;
        return res; 
    }
};