class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int mx[n];
        int mn[n];

        mx[0] = nums[0];
        mn[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            mx[i] = std::max(mx[i - 1], nums[i]);
            mn[n - i - 1] = std::min(mn[n - i], nums[n - i - 1]); 
        }

        int stable = INT_MAX;
        int res = -1;
        for (int i = 0; i < n; i++) {
            int curr_stable = mx[i] - mn[i];
            if (curr_stable <= k) {
                res = i;
                return res;
            }
        }
        return res;
    }
};
/*
6 1 4

6 6 6
1 1 4

5 5 2
*/