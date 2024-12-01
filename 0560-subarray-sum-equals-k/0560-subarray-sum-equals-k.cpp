class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int s = 0, res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            s += nums[i];
            int rem = s - k;
            if (mp.find(rem) != mp.end()) {
                res += mp[rem];
            }
            mp[s] += 1;
        }
        return res;
    }
};