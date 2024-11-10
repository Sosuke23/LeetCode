class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> pref(n + 1), suff(n + 1);
        int res = n + 1;
        if (*max_element(begin(nums), end(nums)) >= k) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] | nums[i];
        }
        
        int j = 0, l = 0;
        for (int i = 1; i <= n; i++) {
            int a = pref[i];
            if (a >= k) {
                res = min(res, i);
                while (j <= i and a >= k) {
                    a ^= pref[j];
                    res = min(res, i - j + 1);
                    j++;
                }
            }
            int b = pref[n] ^ pref[i - 1];
            l = i;
            if (b >= k) {
                res = min(res, n - i + 1);
                while (l <= n and b >= k) {
                    b ^= pref[l];
                    res = min(res, n - l + 1);
                    l++;
                }
            }
        }
        return (res == n + 1 ? -1 : res);
    }
};