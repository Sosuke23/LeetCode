class Solution {
public:
    int minimumLength(string s) {
        int res = 0;
        array<int, 26> cnt {0};
        for (auto x : s) {
            cnt[x - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= 3) {
                res += (cnt[i] & 1 ? 1 : 2);
            } else {
                res += cnt[i];
            }
        }
        return res;
    }
};