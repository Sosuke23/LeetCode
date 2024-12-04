class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int ptr = 0;
        for (int i = 0; i < (int)str1.size(); i++) {
            char nxt = (str1[i] - 'a' + 27) % 26 + 'a';
            cout << nxt << " ";
            if (str2[ptr] == str1[i] or str2[ptr] == nxt) {
                ptr += 1;
                if (ptr == (int)str2.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};