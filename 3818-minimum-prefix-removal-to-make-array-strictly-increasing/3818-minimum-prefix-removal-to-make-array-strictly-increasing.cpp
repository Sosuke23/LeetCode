class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> res(n, 1);
        res[0] = 1;
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                res[i] += res[i - 1];
            }
            if (res[i] == 1) {
                idx = i;
            }
        }

        return idx;

    }
};
/*
1 -1 2 3 3 4 5
1  1 2 3 1 2 3 
*/