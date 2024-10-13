class Solution {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        std::vector<std::vector<int>> res;
        std::sort(begin(nums), end(nums));

        for (int i = 0; i < (int)nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] <= k) {
                res.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else {
                return {};
            }
        }
        return res;
    }
};