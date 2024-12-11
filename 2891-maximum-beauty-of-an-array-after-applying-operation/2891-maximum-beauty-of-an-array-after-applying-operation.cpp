class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 0;
        for (int i = 0, j = 0; i < (int)nums.size(); i++) {
            while (j < (int)nums.size() and nums[j] - nums[i] <= 2 * k) {
                j++;
            }
            res = max(res, j - i);
        }
        return res;
    }
};