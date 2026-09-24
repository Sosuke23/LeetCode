class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        auto dig_sum = [&] (int a) {
            int res = 0;
            while (a) {
                res += a % 10;
                a /= 10;
            }
            return res;
        };

        for (int i = 0; i < (int)nums.size(); i++) {
            if (dig_sum(nums[i]) == i) {
                return i;
            }
        } 
        return -1;
    }
};