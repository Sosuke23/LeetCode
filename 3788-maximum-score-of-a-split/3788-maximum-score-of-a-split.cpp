class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long res = LLONG_MIN;
        int n = (int)nums.size();
        std::vector<long long> pref(n);
        std::vector<long long> suff_min(n);
        pref[0] = nums[0];
        suff_min[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            suff_min[n - i - 1] = std::min(suff_min[n - i], (long long)nums[n - i - 1]);
        }

        for (int i = 0; i + 1 < n; i++) {
            res = std::max(res, pref[i] - suff_min[i + 1]);
        }
        return res;
    }
};