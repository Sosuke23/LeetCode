class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = (int)nums.size();
        int res = 0;
        int mx = nums.back();
        int prev_i = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > mx) {
                res += (prev_i - i) * mx;
                mx = nums[i];
                prev_i = i;
            }
        }

        res += prev_i * mx;
        return res;
    }
};
/*
[4,5,2,8,9,1,3]

mx = 3, prev_i = 6

9 > 3 i = 4
res += (6 - 4) * 3 = 6
mx = 9
prev_i = 4

*/