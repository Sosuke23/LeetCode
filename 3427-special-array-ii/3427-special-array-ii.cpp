class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        vector<int> pref(n);
        for (int i = 0; i < n - 1; i++) {
            pref[i] = ((nums[i] + nums[i + 1]) % 2 == 0) + (i ? pref[i - 1] : 0);
        }
        int q = (int)queries.size();
        vector<bool> res(q);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (l == r) {
                res[i] = 1;
            }
            else {
                res[i] = (pref[r - 1] - (l ? pref[l - 1] : 0)) == 0;
            }
        }
        return res;
    }
};