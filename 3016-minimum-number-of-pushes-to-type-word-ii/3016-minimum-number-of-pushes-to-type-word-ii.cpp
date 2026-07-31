class Solution {
public:
    int minimumPushes(string word) {
        vector<int> Cnt(26, 0);
        for (auto x : word) {
            Cnt[x - 'a'] += 1;
        }   
        int res = 0;
        int mul = 0;
        sort(rbegin(Cnt), rend(Cnt));
        for (int i = 1; i <= 26; i++) {
            if (Cnt[i - 1] == 0) {
                break;
            }
            if (i % 8 == 1) {
                mul += 1;
            }
            res += Cnt[i - 1] * (mul);
        }
        return res;
    }
};