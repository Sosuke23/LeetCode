class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int pref = 0;
        int n = (int)nums.size();
        unordered_multiset<int> m_set;
        unordered_set<int> p;
        for (int i = 0; i < (int)nums.size(); i++) {
            pref += nums[i];
            m_set.insert(nums[i]);
        }
        int res = -2000;
        for (int i = 0; i < n; i++) {
            int now = pref - nums[i];
            m_set.erase(m_set.find(nums[i]));
            if (now & 1) {
                p.insert(nums[i]);
                continue;
            }
            int half = now / 2;
            if (i != n - 1 and m_set.count(half)) {
                res = max(res, nums[i]);
            }
            if (!p.empty() and p.count(half)) {
                res = max(res, nums[i]);
            }
            p.insert(nums[i]);
            
        }
        return res;
    }
};