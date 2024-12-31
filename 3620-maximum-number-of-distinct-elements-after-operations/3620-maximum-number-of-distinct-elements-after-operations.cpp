class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int last = -2e9;
        for (auto it : nums) {
            int x = max(last + 1, it - k);
            if (x > it + k) {
                continue;
            }
            res++;
            last = x;
        }
        return res;
    }
};