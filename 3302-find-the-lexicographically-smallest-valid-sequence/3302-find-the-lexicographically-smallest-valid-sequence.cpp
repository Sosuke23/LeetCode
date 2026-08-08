class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> a(n + 1);
        for (int i = n - 1, j = 0; i >= 0; i--) {
            if (j < m && s[i] == t[m - 1 - j]) {
                j++;
            }
            a[i] = j;
        }
        vector<int> ans;
        for (int i = 0, j = 0, z = 0; i < n && j < m; i++) {
            if (s[i] == t[j]) {
                ans.push_back(i);
                j++;
            } else if (!z && j + 1 + a[i + 1] >= m) {
                ans.push_back(i);
                j++;
                z = 1;
            }
        }
        return ans.size() == m ? ans : vector<int> {};
    }
};