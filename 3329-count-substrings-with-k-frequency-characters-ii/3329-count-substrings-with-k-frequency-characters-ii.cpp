class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        long long res {0};
        int n = (int)s.size();
        std::array<int, 26> freq = {0};

        for (int i = 0, j = 0; i < n; i++) {
            freq[s[i] - 'a']++;

            while (freq[s[i] - 'a'] >= k) {
                res += (n - 1) - i + 1;
                freq[s[j] - 'a']--;
                j++;
            }
        }
        return res;
    }
};