class Solution {
public:
    bool isCircularSentence(string s) {
        s += ' ';
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                if (s[i - 1] != s[0]) {
                    return false;
                }
            } else {
                if (s[i] == ' ') {
                    if (s[i - 1] != s[i + 1]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};