class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int res = 0;
        for (std::string pattern : patterns) {
            if (pattern.size() <= word.size() and word.find(pattern) != -1) {
                res++;
            }
        }
        return res;
    }
};