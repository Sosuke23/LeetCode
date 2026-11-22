class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int res = 0;

        if ((int)nums.size() == 1) {
            return 1;
        }
        
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i == 0 and i + 1 < (int)nums.size()) {
                res += (nums[i] >= nums[i + 1]);
            } else if (i == (int)nums.size() - 1 and i - 1 >= 0) {
                res += (nums[i] >= nums[i - 1]);
            } else {
                res += (nums[i] >= (nums[i - 1] + nums[i + 1] + 1) / 2);
            }
        }
        return res;
    }
};