class Solution {
public:

    bool isAlphanumeric(char c) {
        return ((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9'));
    }
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
                continue;
            }
            if (!isAlphanumeric(s[j])) {
                j--;
                continue;
            }
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};