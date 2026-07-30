class Solution {
public:
    int minimumPushes(string word) {
        int add = 0;
        int res = 0;
        for (int i = 1; i <= (int)word.size(); i++) {
            if (i % 8 == 1) {
                add += 1;
            }
            res += add;
        }
        return res;
    }
};