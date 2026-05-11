class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto x : nums) {
            for (auto y : to_string(x)) {
                res.push_back(y - '0');
            }
        }
        return res;
    }
};