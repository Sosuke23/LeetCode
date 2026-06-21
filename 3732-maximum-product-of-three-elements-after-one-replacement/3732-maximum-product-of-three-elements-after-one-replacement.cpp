class Solution {
public:
    long long maxProduct(vector<int>& nums) {

        const int pos_max = 1e5;
        const int neg_max = -1e5;
        std::sort(begin(nums), end(nums));
        long long res = 1LL * nums[0] * nums.back() * pos_max;
        res = std::max(res, 1LL * nums[0] * nums.back() * neg_max);
        res = std::max(res, 1LL * nums[0] * nums[1] * pos_max);
        res = std::max(res, 1LL * nums[0] * nums[1] * neg_max);
        res = std::max(res, 1LL * nums[(int)nums.size() - 1] * nums[(int)nums.size() - 2] * pos_max);
        res = std::max(res, 1LL * nums[(int)nums.size() - 1] * nums[(int)nums.size() - 2] * neg_max);

        return res;
    }
};