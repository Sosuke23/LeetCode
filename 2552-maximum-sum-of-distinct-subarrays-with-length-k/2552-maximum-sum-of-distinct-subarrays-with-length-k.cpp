class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, pref = 0;
        std::unordered_set<int> ele;
        int n = (int)nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (ele.count(nums[i])) {
                while (!ele.empty() and ele.count(nums[i])) {
                    ele.erase(nums[j]);
                    pref -= nums[j];
                    j++;
                }
            }
            ele.insert(nums[i]);
            pref += nums[i];
            if ((int)ele.size() == k) {
                res = std::max(res, pref);
                ele.erase(nums[j]);
                pref -= nums[j];
                j++;
            }
        }
        return res;
    }
};