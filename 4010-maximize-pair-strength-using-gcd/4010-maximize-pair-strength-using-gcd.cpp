class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long res = 0;
        int n = (int)nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int g = std::gcd(nums[i], nums[j]);
                long long a = 1LL * nums[i] * nums[j];
                a /= (1LL* g * g);
                res = std::max(res, a);
            }
        }
        return res;
    }
};