class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int count_y = std::count(begin(s), end(s), y);
        std::string res = std::string(count_y, y);
        for (char p : s) {
            if (p == y) {
                continue;
            }
            res += p;
        }
        return res;
    }
};