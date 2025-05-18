class Solution {
    bool ok(string& s, string& t) {
        if (s.length() != t.length()) {
            return false;
        }
        bool diff = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                if (diff) {
                    return false;
                }
                diff = true;
            }
        }
        return diff;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> f(n);
        vector<int> from(n);
        int mx = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (f[j] > f[i] && groups[j] != groups[i] && ok(words[i], words[j])) {
                    f[i] = f[j];
                    from[i] = j;
                }
            }
            f[i]++;
            if (f[i] > f[mx]) {
                mx = i;
            }
        }

        int m = f[mx];
        vector<string> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = words[mx];
            mx = from[mx];
        }
        return res;
    }
};