// Problem Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

class Solution {
public:
    int minSwaps(string s) {
        int res = 0;
        int open = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ']') {
                if (open) {
                    open--;
                } else {
                    res += 1;
                    open++;
                }
            } else {
                open++;
            }
        }   
        return res;
    }
};