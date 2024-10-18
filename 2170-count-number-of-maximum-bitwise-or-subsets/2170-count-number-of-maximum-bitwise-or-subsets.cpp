class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0, res = 0;
        for (auto x : nums) {
            max_or |= x;
        }

        function <void(int, int)> Solve = [&] (int idx, int curr) {
            if (curr > (1 << 17)) {
                return;
            }
            res += (curr == max_or);
            for (int i = idx; i < (int)nums.size(); i++) {
                Solve(i + 1, nums[i] | curr);
            }
        };
        Solve(0, 0);
        return res;
    }
};