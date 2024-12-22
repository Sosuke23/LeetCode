class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (float(nums[i] + nums[i + 2]) == float(nums[i + 1] / float(2))) {
                res += 1;
            }
        }
        return res;
    }
};