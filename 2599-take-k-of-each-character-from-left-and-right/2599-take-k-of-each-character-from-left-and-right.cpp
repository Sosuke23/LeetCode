class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = (int)s.size();
        int res = n;
        int a = count(begin(s), end(s), 'a');
        int b = count(begin(s), end(s), 'b');
        int c = count(begin(s), end(s), 'c');

        if (a < k or b < k or c < k) {
            return -1;
        }
        int i = n - 1, j = n - 1;
        while (i >= 0) {
            if (s[i] == 'a') {
                a--;
            }
            if (s[i] == 'b') {
                b--;
            }
            if (s[i] == 'c') {
                c--;
            }
            while (a < k or b < k or c < k) {
                if (s[j] == 'a') {
                    a++;
                }
                if (s[j] == 'b') {
                    b++;
                }
                if (s[j] == 'c') {
                    c++;
                }
                j--;
            }
            res = min(res, i + n - 1 - j);
            i--;
        }
        return res;
    }
};