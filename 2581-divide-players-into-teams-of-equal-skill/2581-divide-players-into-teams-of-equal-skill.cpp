class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        typedef long long i64;
        i64 res = 0;
        sort(begin(skill), end(skill));
        int prev = skill[0] + skill.back();
        res = skill[0] * skill.back();
        int n = (int)skill.size();
        for (int i = 1; i < n / 2; i++) {
            if (skill[i] + skill[n - i - 1] == prev) {
                res += skill[i] * skill[n - i - 1];
            } else {
                return -1;
            }
        }
        return res;
    }
};