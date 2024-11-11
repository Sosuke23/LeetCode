class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> Prime;
        for (int i = 2; i <= 1000; i++) {
            bool ok = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                Prime.push_back(i);
            }
        }
        reverse(Prime.begin(), Prime.end());
        for (int i = 0; i < (int)nums.size(); i++) {
            for (auto p : Prime) {
                if (p < nums[i]) {
                    if (!i or nums[i] - p > nums[i - 1]) {
                        nums[i] -= p;
                        break;
                    }
                }
            }
            if (i and nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};