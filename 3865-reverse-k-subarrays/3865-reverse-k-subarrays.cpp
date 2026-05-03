class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int ele = n / k;
        for (int i = 0; i < n; i += ele) {
            reverse(begin(nums) + i, begin(nums) + (i + ele));
        }
        return nums;
    }
};