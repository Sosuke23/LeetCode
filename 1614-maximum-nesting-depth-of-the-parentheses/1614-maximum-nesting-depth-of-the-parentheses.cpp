class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int open = 0, close = 0;
        close = count(s.begin(), s.end(), ')');
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                open++;
                res = max(res, open);
            } else if (s[i] == ')') {
                open--;
            }
        }
        return res;
    }
};