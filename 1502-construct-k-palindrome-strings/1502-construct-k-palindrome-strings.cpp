class Solution {
public:
    bool canConstruct(string s, int k) {
        if ((int)s.size() < k) {
            return false;
        }
        std::array<int, 26> cnt {0};
        for (auto x : s) {
            cnt[x - 'a'] += 1;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += (cnt[i] % 2 == 1);
        }
        return (res <= k);
    }
};