class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> left(n), right(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        }

        std::vector<int> res(n);
        res[0] = right[1];
        res[n - 1] = left[n - 2];
        for (int i = 1; i + 1 < n; i++) {
            res[i] = left[i - 1] * right[i + 1];
        }
        return res;
    }
};