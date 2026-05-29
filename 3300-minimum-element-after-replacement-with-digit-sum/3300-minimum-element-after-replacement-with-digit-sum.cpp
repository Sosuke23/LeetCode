class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for (auto x : nums) {
            int dig_sum = 0;
            while (x > 0) {
                dig_sum += x % 10;
                x /= 10;
            }
            mn = min(mn, dig_sum);
        }
        return mn;
    }
};