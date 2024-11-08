class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < (int)s.size() and j < (int)t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return (i == (int)s.size());
    }
};