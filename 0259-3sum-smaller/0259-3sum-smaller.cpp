class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        std::sort(begin(nums), end(nums));
        int n = (int)nums.size();
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < target) {
                    res += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};