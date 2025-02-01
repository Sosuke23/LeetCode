class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); i++) {
            if ((nums[i] + nums[i - 1]) % 2 == 0) {
                return false;
            }
        }
        return true;
    }
};