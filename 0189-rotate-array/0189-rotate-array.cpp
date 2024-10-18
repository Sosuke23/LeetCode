class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k %= n;
        std::rotate(begin(nums), begin(nums) + (n - k), end(nums));
    }
};