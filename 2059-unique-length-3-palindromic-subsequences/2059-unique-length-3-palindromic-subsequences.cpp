class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first_index(26,INT_MAX), last_index(26,0);
        for (int i = 0; i < (int)s.size(); i++) {
            first_index[s[i] - 'a'] = min(i, first_index[s[i] - 'a']);
            last_index[s[i] - 'a'] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (first_index[i] < last_index[i]) {
                res += set<char> (begin(s) + first_index[i] + 1, begin(s) + last_index[i]).size();
            }
        }
        return res;
    }
};