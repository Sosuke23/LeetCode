class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int n = nums.size();

        if(target == 0)return n;

        // cout << target << endl;

        unordered_map<int, int> tally;
        tally[0] = -1;

        int result = INT_MAX;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (tally.count(sum - target)) {
                // if ((n - (i - tally[sum - target])) <= result)
                //     cout << i << " " << tally[sum - target] << endl;

                result = min(result, n - (i - tally[sum - target]));
            }

            tally[sum] = i;
        }
        return result == INT_MAX ? -1 : result;
    }
};