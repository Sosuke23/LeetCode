class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        int n = (int)nums.size();
        std::unordered_map<int, std::vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        std::vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            auto it = std::upper_bound(begin(mp[nums[i]]), end(mp[nums[i]]), i + k);
            if (it != end(mp[nums[i]])) {
                res[i] = (int)mp[nums[i]].size() - (it - begin(mp[nums[i]]));
            }
        }
        return res;
    }
};