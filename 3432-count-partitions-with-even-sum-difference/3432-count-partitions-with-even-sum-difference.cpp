class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }

        int curr = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            curr += nums[i];
            sum -= nums[i];
            res += (std::abs(curr - sum) % 2 == 0);
        }
        return res;
    }
};