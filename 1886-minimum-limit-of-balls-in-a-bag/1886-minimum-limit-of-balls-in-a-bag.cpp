class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int lo = 1, hi = 1E9;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int c = 0;
            for (auto x : nums) {
                c += (x - 1) / mid;
            }

            if (c > k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }
};
