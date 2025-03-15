class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int lo = 0, hi = 1E9 + 1;
        int n = (int)nums.size();

        auto Binary_Search = [&](int kk, int miid) {
            int i = 0;
            while (i < n) {
                if (nums[i] <= miid) {
                    i += 2;
                    kk--;
                } else {
                    i++;
                }
                if (kk == 0) {
                    return true;
                }
            }
            return (kk == 0);
        };
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (Binary_Search(k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};