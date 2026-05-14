class Solution {
public:
    long long validSubarrays(vector<int>& nums, int k) {
        long long res = 0;

        if ((int)nums.size() < 3) {
            return 0;
        }

        int prev_peak = -1, prev_prev_peak = -1;
        
        for (int i = 1;  i < (int)nums.size() - 1 ; i++) {
            if (nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) {
                if (prev_peak != -1) {
                    long long left = std::min(prev_peak - prev_prev_peak, k + 1);
                    long long right = std::min(i - prev_peak, k + 1);

                    res += 1LL * left * right;
                    prev_prev_peak = prev_peak;
                }

                prev_peak = i;
            }
        }

        if (prev_peak != -1) {
            long long left = std::min(prev_peak - prev_prev_peak, k + 1);
            long long right = std::min((int)nums.size() - prev_peak, k + 1);

            res += 1LL * left * right;
        }

        return res;
    }
};