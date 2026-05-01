class Solution {
public:
    vector<int> sortByAbsoluteValue(vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> p(n, 0);
        std::iota(begin(p), end(p), 0);

        std::sort(begin(p), end(p), [&] (const auto &i, const auto &j) {
            return std::abs(nums[i]) < std::abs(nums[j]);
        });

        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[p[i]]);
        }

        return res;

    }
};