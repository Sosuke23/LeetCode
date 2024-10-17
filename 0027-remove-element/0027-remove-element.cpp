class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::vector<int> p;
        int res = 0;
        for (auto x : nums) {
            if (x != val) {
                res += 1;
                p.push_back(x);
            }
        }
        nums = p;
        return res;
    }
};