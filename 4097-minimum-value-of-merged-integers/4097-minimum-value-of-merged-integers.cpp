class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n {(int)nums.size()};
        int mn {INT_MAX};

        for (int i = 0; i < n; i += 2) {
            std::string s = std::to_string(nums[i]) + std::to_string(nums[i + 1]);
            mn = std::min(mn, std::stoi(s));
        }

        return mn;
    }
};