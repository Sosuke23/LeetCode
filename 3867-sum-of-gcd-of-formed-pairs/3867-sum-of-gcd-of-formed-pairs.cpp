class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> prefix_gcd(n);
        prefix_gcd[0] = nums[0];
        int mx = nums[0];

        for (int i = 1; i < n; i++) {
            mx = std::max(mx, nums[i]);
            prefix_gcd[i] = std::gcd(nums[i], mx);
        }

        std::sort(begin(prefix_gcd), end(prefix_gcd));
        long long res = 0;
        for (int i = 0; i < n / 2; i++) {
            res += std::gcd(prefix_gcd[i], prefix_gcd[n - i - 1]);
        }
        return res;
    }
};