class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        std::array<int, 26> cnt {0};
        std::vector<std::string> res;
        for (auto x : words2) {
            std::array<int, 26> b {0};
            for (auto c : x) {
                b[c - 'a'] += 1;
                cnt[c - 'a'] = std::max(cnt[c - 'a'], b[c - 'a']);
            }
        }

        for (auto x : words1) {
            std::array<int, 26> a {0};
            for (auto c : x) {
                a[c - 'a'] += 1;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (a[i] >= cnt[i]) {
                    continue;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.push_back(x);
            }
        } 
        return res;

    }
};