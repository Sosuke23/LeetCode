class Solution {
public:
    int minimumRecolors(string s, int k) {
        int res = INT_MAX;
        for (int i = 0; i <= (int)s.size() - k; i++) {
            string a = s.substr(i, k);
            res = min(res, (int)count(begin(a), end(a), 'W'));
        }
        return res;
    }
};