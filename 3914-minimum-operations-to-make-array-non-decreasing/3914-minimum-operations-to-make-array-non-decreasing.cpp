class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long res = 0;
        for (int i = 1; i < (int)nums.size(); i++) {
            res += std::max(0, nums[i - 1] - nums[i]);
        }
        return res;
    }
};