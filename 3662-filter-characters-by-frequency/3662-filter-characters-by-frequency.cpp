class Solution {
public:
    string filterCharacters(string s, int k) {
        std::string res = "";
        for (char c : s) {
            if (std::count(begin(s), end(s), c) < k) {
                res += c;
            }
        }
        return res;
    }
};