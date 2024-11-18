class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        std::vector<int> pref(n + 1);
        for (auto &q : queries) {
            pref[q[0]]++;
            pref[q[1] + 1]--;
        }

        for (int i = 1; i <= n; i++) {
            pref[i] += pref[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (pref[i] < nums[i]) {
                return false;
            }
        }
        return true;
    }
};