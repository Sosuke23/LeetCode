class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                i += 1;
            } else {
                res.push_back(nums[i]);
            }
        }
        if ((int)res.size() == 1) {
            res.push_back(nums.back());
        }
        return res;
    }
};