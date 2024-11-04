class Solution {
public:
    string compressedString(string word) {
        char prev = word[0];
        string res = "";
        int occur = 1;
        int n = (int)word.size();
        for (int i = 1; i < n; i++) {
            if (occur == 9) {
                res += to_string(occur) + prev;
                prev = word[i];
                occur = 1;
                continue;
            }
            if (word[i] == prev) {
                occur++;
            } else {
                res += to_string(occur) + prev;
                prev = word[i];
                occur = 1;
            }
        }

        res += to_string(occur) + prev;
        return res;
    }
};