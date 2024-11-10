class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> right(nums.size());
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            right[i] = 1;
            if (i + 1 < (int)nums.size() && nums[i + 1] > nums[i]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int cur = 0;
        int res = 0;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (i > 0 && nums[i] > nums[i - 1]) {
                cur++;
            }
            else {
                cur = 1;
            }
            res = max(res, min(cur, right[i + 1]));
        }
        return res;
    }
};