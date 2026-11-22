class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peak {0};
        int valley {0};

        for (int i = 1; i + 1 < (int)nums.size(); i++) {
            peak += ((nums[i] > nums[i - 1] and nums[i] > nums[i + 1]) ? nums[i] : 0);
            valley += ((nums[i] < nums[i - 1] and nums[i] < nums[i + 1]) ? nums[i] : 0);
        }

        return peak - valley;
    }
};