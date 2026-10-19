class Solution {
public:
    int minRotations(string s) {
        int res = 0;
        int now = 0;
        for (char x : s) {
            int to = x - '0';
            res += std::min(std::abs(to - now), 10 - std::abs(to - now));
            now = to;
        }
        return res;
    }
};