class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size();
        int q = queries.size();
        int i;
        vector<int> prefix(n + 1, 0);

        for (i = 0; i < n; i++) {
            string t = words[i];
            int s = t.size();
            if ((t[0] == 'a' || t[0] == 'e' || t[0] == 'i' || t[0] == 'o' ||
                 t[0] == 'u') &&
                (t[s - 1] == 'a' || t[s - 1] == 'e' || t[s - 1] == 'i' ||
                 t[s - 1] == 'o' || t[s - 1] == 'u')) {
                prefix[i + 1] = prefix[i] + 1;
            } else {
                prefix[i + 1] = prefix[i];
            }
        }

        vector<int> res;

        for (i = 0; i < q; i++) {
            int l, r;
            l = queries[i][0];
            r = queries[i][1];
            res.push_back(prefix[r + 1] - prefix[l]);
        }

        return res;
    }
};