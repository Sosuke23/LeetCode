class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) {
            return 1;
        }
        int n = (int)nums.size();
        int res = n + 1, j = 0, kk = 0;
        array<int, 32> C {0};
        auto Add = [&] (int idx) {
            for (int i = 0; i < 31; i++) {
                if ((1 << i) & nums[idx]) {
                    C[i]++;
                    if (C[i] == 1) {
                        kk += (1 << i);
                    }
                }
            }
        };

        auto Remove = [&] (int idx) {
            for (int i = 0; i < 31; i++) {
                if ((1 << i) & nums[idx]) {
                    C[i]--;
                    if (C[i] == 0) {
                        kk -= (1 << i);
                    }
                }
            }
        };

        for (int i = 0; i < n; i++) {
            while (j < n and kk < k) {
                Add(j);
                ++j;
            }
            if (kk >= k) {
                res = min(res, j - i);
            }
            Remove(i);
        }
        return (res == n + 1 ? -1 : res);
    }
};