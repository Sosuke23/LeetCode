class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            if (i > curr) {
                return false;
            }
            curr = std::max(curr, i + nums[i]);
        }
        return true;
    }
};