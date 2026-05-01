class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        int res = 0;
        for (int x : daysLate) {
            if (x == 1) {
                res += 1;
            } else if (x <= 5) {
                res += 2 * x;
            } else {
                res += 3 * x;
            }
        }
        return res;
    }
};