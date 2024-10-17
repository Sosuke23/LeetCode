class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ((int)nums.size() == 1) {
            return 1;
        }
        vector<int> p;
        p.push_back(nums[0]);
        int c = 1;
        p.push_back(nums[1]);
        c += 1;
        for (int i = 2; i < (int)nums.size(); i++) {
            if (p.back() == nums[i] and p[c - 2] != nums[i]) {
                p.push_back(nums[i]);
                c += 1;
            } else if (p.back() != nums[i]) {
                p.push_back(nums[i]);
                c += 1;
            }
        }
        nums = p;
        return c;
    }
};