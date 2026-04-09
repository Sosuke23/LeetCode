class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 30; i++) {
            std::vector<int> arr;
            for (auto x : nums) {
                if ((x & (1 << i)) != 0) {
                    if (arr.empty() or arr.back() < x) {
                        arr.push_back(x);
                    } else {
                        *lower_bound(begin(arr), end(arr), x) = x;
                    }
                }
            }
            res = std::max(res, (int)arr.size());
        }

        return res;
    }
};