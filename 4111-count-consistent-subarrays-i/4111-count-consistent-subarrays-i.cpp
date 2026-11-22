class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = (int)nums.size();

        int res {0};
        for (int i = 0; i < n; i++) {
            int mn = nums[i];
            int _and = nums[i];
            res++;
            for (int j = i + 1; j < n; j++) {
                mn = std::min(mn, nums[j]);
                _and &= nums[j];
                res += (_and == mn);
            }
        }

        return res;
    }
};