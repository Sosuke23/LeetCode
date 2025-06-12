class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = std::abs(nums[0] - nums.back());

        for (int i = 0; i < (int)nums.size() - 1; i++) {
            res = std::max(res, std::abs(nums[i] - nums[i + 1]));
        }   
        return res;
    }
};