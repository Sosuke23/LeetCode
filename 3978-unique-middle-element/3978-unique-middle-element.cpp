class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = (int)nums.size();
        int ele = nums[n / 2];
        for (int i = 0; i < n / 2; i++) {
            if (nums[i] == ele or nums[n - i - 1] == ele) {
                return false;
            }
        }
        return true;
    }
};