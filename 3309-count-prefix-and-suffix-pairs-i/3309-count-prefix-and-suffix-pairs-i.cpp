class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;

        auto isPrefixAndSuffix = [&] (std::string a, std::string b) {
            bool ok1 = (b.find(a) == 0);
            reverse(begin(a), end(a));
            reverse(begin(b), end(b));
            bool ok2 = (b.find(a) == 0);
            return (ok1 and ok2);
        };

        int n = (int)words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return res;
    }
};