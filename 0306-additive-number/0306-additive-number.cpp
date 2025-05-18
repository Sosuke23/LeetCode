class Solution {
public:
    #define i23 long long 
    bool backTrack(string &s, int idx, i23 prev, i23 nxt, int l) {
        if (idx == (int)s.size()) {
            return (l > 2);
        }

        i23 curr = 0;
        for (int i = idx; i < (int)s.size(); i++) {
            if (curr > pow(10, 17)) {
                break;
            }
            curr = curr * 10 + (s[i] - '0');

            bool ok = false;
            
            if (prev + nxt == curr or l < 2) {
                ok = backTrack(s, i + 1, nxt, curr, l + 1);
            }
            if (ok) {
                return true;
            }

            if (curr == 0) {
                break;
            }

        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        return backTrack(num, 0, 0, 0, 0);
    }
};