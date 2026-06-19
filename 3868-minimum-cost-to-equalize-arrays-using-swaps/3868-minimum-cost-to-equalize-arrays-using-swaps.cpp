class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> cnt1, cnt2, cnt;
        for (int x : nums1) {
            cnt[x]++;
            cnt1[x]++;
        }
        for (int x : nums2) {
            cnt[x]++;
            cnt2[x]++;
        }

        int res = 0;
        for (auto [ele, val] : cnt) {
            if (val % 2 == 1) {
                return -1;
            }

            res += std::min(std::abs(val / 2 - cnt1[ele]), std::abs(val / 2 - cnt2[ele]));
        }

        res /= 2;
        return res;

    }
};