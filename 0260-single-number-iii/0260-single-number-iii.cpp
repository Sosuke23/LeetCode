class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x] += 1;
        }
        vector<int> res;
        for (auto &[key, val] : mp) {
            if (val == 1) {
                res.push_back(key);
            }
            if ((int)res.size() == 2) {
                break;
            }
        }
        return res;
    }
};