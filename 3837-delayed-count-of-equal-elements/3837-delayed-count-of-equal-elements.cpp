class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        int n = (int)nums.size();
        std::vector<int> res(n, 0);
        std::unordered_map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {
            if (i + k + 1 < n) {
                mp[nums[i + k + 1]]++;
            }
            res[i] = mp[nums[i]];
        }
        return res;
    }
};