class Solution {
public:
    string maximumXor(string s, string t) {
        int zero = count(begin(t), end(t), '0');
        int one = count(begin(t), end(t), '1');

        std::string res = "";
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') {
                if (zero) {
                    res += '1';
                    zero--;
                } else {
                    res += '0';
                    one--;
                }
            } else if (s[i] == '0') {
                if (one) {
                    res += '1';
                    one--;
                } else {
                    res += '0';
                    zero--;
                }
            }
        }
        return res;
    }
};