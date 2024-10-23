class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> a, b;
        for (auto x : s) {
            a[x] += 1;
        }
        int res = 0;
        
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            b[s[i]] += 1;
            a[s[i]] -= 1;
            if (a[s[i]] == 0) {
                a.erase(s[i]);
            }
            res += ((int)a.size() == (int)b.size());
        }
        return res;
    }
};