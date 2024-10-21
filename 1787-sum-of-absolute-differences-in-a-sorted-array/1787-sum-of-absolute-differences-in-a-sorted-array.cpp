class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> pref(n, 0), suff(n, 0);
        pref[0] = nums[0], suff[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            suff[n - i - 1] = suff[n - i] + nums[n - i - 1];
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int now = ((nums[i] * i) - pref[i]) + (suff[i] - (nums[i] * (n - i - 1)));
            res[i] = now;
        }
        return res;
    }
};
