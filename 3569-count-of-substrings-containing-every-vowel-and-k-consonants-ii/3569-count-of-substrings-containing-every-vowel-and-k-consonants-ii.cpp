class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        typedef long long i23;
        int n = (int)word.size();
        
        auto vowel = [&](char c) {
            return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
        };

        auto f = [&](int k) {
            i23 res = 0;
            array<int, 26> cnt = {0};
            int good = 0, cons = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n and (good < 5 or cons < k)) {
                    if (vowel(word[j])) {
                        int p = cnt[word[j] - 'a']++;
                        if (p == 0) {
                            good++;
                        }
                    } else {
                        cons++;
                    }
                    j++;
                }
                if (good == 5 and cons >= k) {
                    res += n - j + 1;
                }
                if (vowel(word[i])) {
                    int p = --cnt[word[i] - 'a'];
                    if (p == 0) {
                        good--;
                    }
                } else {
                    cons--;
                }
            }
            return res;
        };
        return f(k) - f(k + 1);
    }
};