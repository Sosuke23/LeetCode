class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = (int)nums.size();
        bool ok = true;
        while (ok) {
            ok = false;
            for (int i = 0; i + 1 < n; i++) {
                int A = __builtin_popcount(nums[i]);
                int B = __builtin_popcount(nums[i + 1]);
                if (nums[i] > nums[i + 1] and (A == B)) {
                    swap(nums[i], nums[i + 1]);
                    ok = true;
                }
            }
        }
        return is_sorted(begin(nums), end(nums));
    }
};