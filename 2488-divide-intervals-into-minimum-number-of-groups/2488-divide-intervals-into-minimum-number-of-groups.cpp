class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        std::array<int, 1000005> cnt = {0};
        for (auto i : intervals) {
            cnt[i[0]] += 1;
            cnt[i[1] + 1] -= 1;
        }

        int res = 0;
        for (int i = 1; i <= 1000000; i++) {
            cnt[i] += cnt[i - 1];
            res = std::max(res, cnt[i]);
        }
        return res;
    }
};