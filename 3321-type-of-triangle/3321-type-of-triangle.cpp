class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        int a = nums[0] + nums[1];
        if (a <= nums[2]) {
            return "none";
        }
        if (nums[0] == nums[1] and nums[1] == nums[2]) {
            return "equilateral";
        }
        else if (nums[0] == nums[1] or nums[1] == nums[2]) {
            return "isosceles";
        }
        return "scalene";
    }
};