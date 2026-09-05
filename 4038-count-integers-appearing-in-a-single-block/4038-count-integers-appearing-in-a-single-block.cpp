class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = (int)nums.size();
        std::unordered_map<int, int> cnt;
        std::vector<std::array<int, 2>> pos(101); // {min_pos, max_pos}

        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] == 1) {
                pos[nums[i]] = {i, i};
            } else {
                pos[nums[i]][1] = i;
            }
        }

        int res = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] == 0) {
                continue;
            }
            res += (pos[i][1] - pos[i][0] + 1 == cnt[i]);
        }

        return res;
    }
};