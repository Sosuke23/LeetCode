class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int prod = INT_MIN;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target and nums[i] != nums[j]) {
                    if (nums[i] * nums[j] > prod) {
                        prod = nums[i] * nums[j];
                        if (nums[i] > nums[j]) {
                            res = {i, j};
                        } else {
                            res = {j, i};
                        }
                    }
                }
            }
        }
        return res;
    }
};