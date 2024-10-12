class Solution {
public:
    bool isPalindrome(int x) {
        string p = to_string(x);
        int n = (int)p.size();
        for (int i = 0; i < (int)p.size() / 2; i++) {
            if (p[i] != p[n - i - 1]) {
                return false;
            }
        }   
        return true;
    }
};