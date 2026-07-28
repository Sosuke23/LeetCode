class Solution {
public:
    string smallestPalindrome(string s) {
        std::array<int, 26> cnt {0};
        for (auto x : s) {
            cnt[x - 'a']++;
        }

        std::string res = "";
        int odd = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                res += std::string(cnt[i] / 2, 'a' + i);
            } 
            if (cnt[i] % 2 == 1) {
                odd = i;
            }
        }

        std::string a = res;
        reverse(begin(a), end(a));
        if (odd != -1) {
            res += ('a' + odd);
        }
        
        res += a;
        return res;
        

    }
};