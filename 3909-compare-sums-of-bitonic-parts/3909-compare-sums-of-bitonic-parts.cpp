class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = (int)nums.size();
        long long ascend = nums[0], descend = 0;
        bool found = false;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                ascend += nums[i];
            } else if (nums[i] < nums[i - 1]) {
                if (!found) {
                    descend = nums[i - 1];
                    found = true;
                }
                descend += nums[i];
            }
        }
        return (ascend > descend ? 0 : (descend > ascend ? 1 : -1));
    }
};