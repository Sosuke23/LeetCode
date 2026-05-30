class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = (int)nums.size();
        for (int i = 1; i < n; i++) {
            int missing_number = (nums[i] - nums[i - 1] - 1);
            if (missing_number >= k) {
                return nums[i - 1] + k;
            }
            k -= missing_number;
        }
        return nums[n - 1] + k;
    }
};