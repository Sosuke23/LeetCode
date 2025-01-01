class Solution {
public:
    int maxScore(string s) {

        if (s == string((int)s.size(), s[0])) {
            return (int)s.size() - 1;
        }

        int res = 0;
        int one = count(begin(s), end(s), '1'), zero = 0;
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            if (s[i] == '0') {
                zero += 1;
            }
            else {
                one -= 1;
            }
            res = max(res, one + zero);
        }

        return res;
    }
};