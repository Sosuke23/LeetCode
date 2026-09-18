class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> pos;
        for (int i = 0; i < (int)nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }

        int res = 0;
        for (auto [ele, idx] : pos) {
            if (idx.size() == 3) {
                res += (idx[1] - idx[0] == idx[2] - idx[1]);
            }
        }

        return res;
    }
};