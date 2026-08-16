class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        array<int, 3> cnt {0};
        for (auto x : stones) {
            cnt[x % 3]++;
        }

        if (min(cnt[1], cnt[2]) == 0) {
            return (max(cnt[1], cnt[2]) > 2 and cnt[0] % 2 == 1);
        }
        return (abs(cnt[1] - cnt[2]) > 2 or cnt[0] % 2 == 0);
    }
};