class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        std::array<std::array<int, 26>, 26> cnt = {0};
        for (auto x : words) {
            if (cnt[x[1] - 'a'][x[0] - 'a']) {
                res += 4;
                cnt[x[1] - 'a'][x[0] - 'a'] -= 1;
            } else {
                cnt[x[0] - 'a'][x[1] - 'a'] += 1;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (cnt[i][i]) {
                res += 2;
                break;
            }
        }
        return res;
    }
};