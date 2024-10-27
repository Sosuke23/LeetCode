class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        typedef long long i23;
        const int MOD = 1'000'000'007;
        std::array<i23, 26> cnt = {0};
        for (int i = 0; i <= 25; i++) {
            cnt[i] = 0;
        }

        for (auto x : s) {
            cnt[x - 'a'] += 1;
        }
        for (int i = 1; i <= t; i++) {
            std::array<int, 26> new_cnt = {0};
            for (int j = 0; j < 25; j++) {
                new_cnt[j + 1] = cnt[j];
            }
            new_cnt[0] = (new_cnt[0] + cnt[25]) % MOD;
            new_cnt[1] = (new_cnt[1] + cnt[25]) % MOD;

            for (int j = 0; j < 26; j++) {
                cnt[j] = new_cnt[j];
            }
        }
        i23 res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + cnt[i]) % MOD;
        }
        return res;
    }
};