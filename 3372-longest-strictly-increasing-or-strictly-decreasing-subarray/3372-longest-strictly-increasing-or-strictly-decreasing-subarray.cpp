class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res_a = 1, res_b = 1;
        int cnt_a = 1, cnt_b = 1;

        int prev_a = nums[0], prev_b = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > prev_a) {
                prev_a = nums[i];
                cnt_a += 1;
            } else {
                prev_a = nums[i];
                res_a = max(res_a, cnt_a);
                cnt_a = 1;
            }

            if (nums[i] < prev_b) {
                prev_b = nums[i];
                cnt_b += 1;
            } else {
                prev_b = nums[i];
                res_b = max(res_b, cnt_b);
                cnt_b = 1;
            }
        }
        res_a = max(res_a, cnt_a);
        res_b = max(res_b, cnt_b);
        return max(res_a, res_b);
    }
};