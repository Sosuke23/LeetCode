class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        long long res = 0;
        int j = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            while (j < (int)nums.size()  and ((int)ms.size() == 0 or (*ms.rbegin() - *ms.begin()) <= 2)) {
                ms.insert(nums[j]);
                j += 1;
            }
            res += j - i - 1;
            if (*ms.rbegin() - *ms.begin() <= 2) {
                res += 1;
            }
            ms.erase(ms.find(nums[i]));
        }
        return res;
    }
};
