class Solution {
public:
    
    int maximumLengthSubstring(string s) {
        int res = 0;
        int n = (int)s.size();
        
        auto check = [&] (map<char, int> A) {
            for (auto & [_, val] : A) {
                if (val > 2) {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            map<char, int> cnt;
            cnt[s[i]]++;
            for (int j = i + 1; j < n; j++) {
                cnt[s[j]]++;
                if (check(cnt)) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};
