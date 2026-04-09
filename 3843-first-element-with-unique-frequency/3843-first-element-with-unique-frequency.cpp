class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        std::unordered_map<int, int> mp, a, pos;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            mp[nums[i]]++;
            pos[nums[i]] = i;
        }

        for (auto &[key, val] : mp) {
            a[val]++;
        }

        int max_pos = (int)nums.size() + 1;
        int res = -1;
        for (auto &[key, val] : a) {
            if (val == 1) {
                for (auto &[_key, _val] : mp) {
                    if (_val == key && pos[_key] < max_pos) {
                        max_pos = pos[_key];
                        res = _key;
                    }
                }
            }
        }

        return res;
        
    }
};