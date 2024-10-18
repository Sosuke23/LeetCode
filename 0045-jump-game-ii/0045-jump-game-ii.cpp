class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size(), res = 0;
        int lo = 0, hi = 0;
        while (hi < n - 1) {
            res += 1;
            int maxEnd = hi + 1;
            for (int i = lo; i <= hi; i++) {
                if (i + nums[i] >= n - 1) {
                    return res;
                }
                maxEnd = max(maxEnd, i + nums[i]);
            }
            lo = hi + 1;
            hi = maxEnd;
        }
        return res;
    }
};