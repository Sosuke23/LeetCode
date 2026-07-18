class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = __gcd(nums.front(), nums.back());
        return res;
    }
};