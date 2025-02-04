class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int temp = nums[0];
        int prev = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                temp += nums[i];
            } else {
                res = max(res, temp);
                temp = nums[i];
            }
        }
        res = max(res, temp);
        return res;
    }
};