class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = (int)s.size();
        if (s == goal) {
            return true;
        }
        for (int i = 1; i < n; i++) {
            rotate(begin(s), begin(s) + 1, end(s));
            if (s == goal) {
                return true;
            }
        }
        return false;
    }
};