class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        std::vector<int> res = nums;
        reverse(begin(nums), end(nums));
        res.insert(res.end(), begin(nums), end(nums));
        return res;
    }
};