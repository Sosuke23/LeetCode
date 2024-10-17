class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int> p;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (p.empty()) {
                p.push_back(nums[i]);
                continue;
            } 

            if (p.back() != nums[i]) {
                p.push_back(nums[i]);
            }
        }
        nums = p;
        return (int)p.size();
    }
};