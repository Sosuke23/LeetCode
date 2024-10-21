class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> p = nums;
        p.insert(begin(p), begin(nums), end(nums));
        return p;
    }
};