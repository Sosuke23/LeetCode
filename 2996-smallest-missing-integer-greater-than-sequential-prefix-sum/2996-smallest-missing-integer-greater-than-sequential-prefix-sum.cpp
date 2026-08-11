class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int f = nums[0];
        int pref = f;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                f = nums[i];
                pref += f;
            }
            else {
                break;
            }
        }
        while (count(begin(nums), end(nums), pref)) {
            pref += 1;
        }
        return pref;
    }
};
