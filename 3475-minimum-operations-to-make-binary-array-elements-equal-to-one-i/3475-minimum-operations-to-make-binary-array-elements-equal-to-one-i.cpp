class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        int n = (int)nums.size();
        for (int i = 0; i + 2 < n; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                res += 1;
            }
        }
        
        if (count(begin(nums), end(nums), 0)) {
            return -1;
        }
        return res;
    }
};