class Solution {
public:
    int numberOfSpecialChars(string word) {
        array<int, 26> lo {-1};
        array<int, 26> up {INT_MAX};
        for (int i = 0; i < 26; i++) {
            lo[i] = -1;
            up[i] = INT_MAX;
        }

        for (int i = 0; i < (int)word.size(); i++) {
            if (word[i] >= 'a' and word[i] <= 'z') {
                lo[word[i] - 'a'] = max(lo[word[i] - 'a'], i);
            } else {
                up[word[i] - 'A'] = min(up[word[i] - 'A'], i);
            }
        }

        int res = 0;
        cout << lo[0] << " " << up[0] << '\n';
        cout << lo[1] << " " << up[1] << '\n';
        cout << lo[2] << " " << up[2] << '\n';
        for (int i = 0; i < 26; i++) {
            if (lo[i] == -1 or up[i] == INT_MAX) {
                continue;
            }
            res += (lo[i] < up[i]);
        }
        return res;
    }
};