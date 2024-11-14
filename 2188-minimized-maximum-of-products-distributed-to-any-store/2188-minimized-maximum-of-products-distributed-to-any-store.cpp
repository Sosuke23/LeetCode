class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int lo = 1, hi = 100000;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            int sum = 0;
            for (auto x : q) {
                sum += (x + mid - 1) / mid;
            }
            if (sum > n) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return lo;
    }
};