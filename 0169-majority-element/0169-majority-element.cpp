class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
            if (mp[x] > (int)nums.size() / 2) {
                return x;
            }
        }
        return 1;
    }
};