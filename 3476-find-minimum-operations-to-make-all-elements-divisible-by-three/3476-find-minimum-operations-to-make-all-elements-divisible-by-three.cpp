class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (auto &x : nums) {
            x %= 3;
            res += (x != 0);
        }
        return res;
    }
};