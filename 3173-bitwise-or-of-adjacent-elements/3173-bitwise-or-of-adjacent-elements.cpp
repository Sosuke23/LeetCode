class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> res(n - 1);
        for (int i = 0; i < n - 1; i++) {
            res[i] = nums[i] | nums[i + 1];
        }
        return res;
    }
};