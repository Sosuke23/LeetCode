class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        std::vector<int> res;
        std::vector<long long> pref(n, 0), suff(n, 0);
        for (int i = 0; i < n - 1; i++) {
            long long diff_right = nums[i + 1] - nums[i];
            long long diff_left = LLONG_MAX;
            if (i > 0) {
                diff_left = nums[i] - nums[i - 1];
            }

            pref[i + 1] = pref[i] + (diff_right < diff_left ? 1 : diff_right);
        }

        for (int i = n - 1; i > 0; i--) {
            long long diff_left = nums[i] - nums[i - 1];
            long long diff_right = LLONG_MAX;

            if (i < n - 1) {
                diff_right = nums[i + 1] - nums[i];
            }

            suff[i - 1] = suff[i] + (diff_left <= diff_right ? 1 : diff_left);
        }

        for (std::vector<int> q : queries) {
            if (q[0] <= q[1]) {
                res.push_back(pref[q[1]] - pref[q[0]]);
            } else {
                res.push_back(suff[q[1]] - suff[q[0]]);
            }
        }
        return res;


    }
};