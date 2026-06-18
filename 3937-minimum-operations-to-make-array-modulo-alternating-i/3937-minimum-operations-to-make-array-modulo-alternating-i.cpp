class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = (int)nums.size();
        for (int &x : nums) {
            x %= k;
        }

        int res = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) {
                    continue;
                }
                int ops = 0;
                for (int i = 0; i < n; i++) {
                    if (i & 1) {
                        ops += std::min(std::abs(nums[i] - x), k - std::abs(nums[i] - x));
                    } else {
                        ops += std::min(std::abs(nums[i] - y), k - std::abs(nums[i] - y));
                    }
                }
                res = std::min(res, ops);
            }
        }
        return res;
    }
};