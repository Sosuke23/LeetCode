class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int res = 0;
        int p = k;
        while (true) {
            if (!count(begin(nums), end(nums), k)) {
                return k;
            }
            k += p;
        }
        return res;
    }
};