class Solution {
public:
    int lengthOfLastWord(string s) {
        while (!s.empty() and s.back() == ' ') {
            s.pop_back();
        }
        int res = 0;
        while (!s.empty() and s.back() != ' ') {
            s.pop_back();
            res += 1;
        }
        return res;
    }
};