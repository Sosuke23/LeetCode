class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res = 0;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            auto itt = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;
            if (it <= itt) {
                res += 1LL * (itt - it + 1);
            }
        }
        return res;
    }
};