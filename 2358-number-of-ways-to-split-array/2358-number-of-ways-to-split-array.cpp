class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = (int)nums.size();
        int cnt = 0;
        long long sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long chk = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            chk += nums[i];
            if (chk >= sum - chk) {
                cnt++;
            }
        }
        return cnt;
    }
};