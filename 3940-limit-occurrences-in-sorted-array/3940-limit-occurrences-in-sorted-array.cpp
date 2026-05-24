class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        std::vector<int> res;
        for (int x : nums) {
            mp[x]++;
            if (mp[x] <= k) {
                res.push_back(x);
            }
        }
        return res;
    }
};