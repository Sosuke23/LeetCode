class Solution {
public:
    int longestCommonPrefix(string s, string t) {
        int res = 0;
        for (int i = 0, j = 0; i < (int)s.size() && j < (int)t.size(); i++) {
            if (s[i] == t[j] and i - j < 2) {
                res++;
                j++;
            }
        }
        return res;
    }
};