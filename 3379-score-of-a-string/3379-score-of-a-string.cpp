class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            res += abs((int)s[i] - (int)s[i - 1]);
        }
        return res;
    }  
};
