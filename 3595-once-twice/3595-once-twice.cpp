class Solution {
public:
    vector<int> onceTwice(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        std::vector<int> res(2, 0);
        for (auto &[key, val] : mp) {
            if (val == 1) {
                res[0] = key;
            } else if (val == 2) {
                res[1] = key;
            }
        }
        return res;
    }
};