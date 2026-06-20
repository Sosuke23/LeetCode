class Solution {
public:
    string mergeCharacters(string s, int k) {
        std::string res = "";

        std::array<int, 26> cnt {0};

        for (char x : s) {
            if (cnt[x - 'a']) {
                continue;
            }
            res += x;
            cnt[x - 'a']++;

            if ((int)res.size() > k) {
                cnt[res[(int)res.size() - k - 1] - 'a']--;
            }
        }
        return res;
    }
};