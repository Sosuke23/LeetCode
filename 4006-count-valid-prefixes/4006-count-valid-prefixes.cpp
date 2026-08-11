class Solution {
public:
    int countValidPrefixes(string s) {
        int one = 0, zero = 0;
        int res = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            one += (s[i] == '1');
            zero += (s[i] == '0');

            if (std::abs(one - zero) <= 1) {
                res++;
            }
        }
        return res;
    }
};