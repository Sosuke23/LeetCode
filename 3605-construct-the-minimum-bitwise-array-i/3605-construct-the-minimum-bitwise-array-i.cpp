class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int k = 31;
            for (k = 0; k < 31; k++) {
                if (!(x & (1 << k))) {
                    break;
                }
            }
            bool ok = false;
            for (int j = k - 1; j >= 0; j--) {
                x ^= (1 << j);
                if ((x | (x + 1)) == nums[i]) {
                    res[i] = x;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                res[i] = -1;
            }
        }
        return res;
    }
};
