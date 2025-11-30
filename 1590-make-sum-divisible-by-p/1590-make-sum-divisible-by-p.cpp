class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = (int)nums.size();
        int goal = 0;
        for (auto x : nums) {
            (goal += x) %= p;
        }

        unordered_map<int, int> mp = {{0, -1}};
        int curr = 0;
        int res = INT_MAX;
        if (goal == 0) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            (curr += nums[i]) %= p;
            int need = (curr - goal + p) % p;
            if (mp.find(need) != mp.end()) {
                res = min(res, i - mp[need]);
            }
            mp[curr] = i;
        }

        if (res >= n) {
            return -1;
        }
        return res;
    }
};