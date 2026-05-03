class Solution {
public:
    int totalDistance(string s) {
        std::string a = "qwertyuiop";
        std::string b = "asdfghjkl";
        std::string c = "zxcvbnm";

        int prev_r = 1, prev_c = 0;
        int res = 0;
        for (char x : s) {
            auto it_a = std::find(begin(a), end(a), x);
            auto it_b = std::find(begin(b), end(b), x);
            auto it_c = std::find(begin(c), end(c), x);

            if (it_a != end(a)) {
                res += std::abs(prev_r - 0) + std::abs(prev_c - (it_a - begin(a)));
                prev_r = 0, prev_c = (it_a - begin(a));
            } else if (it_b != end(b)) {
                res += std::abs(prev_r - 1) + std::abs(prev_c - (it_b - begin(b)));
                prev_r = 1, prev_c = (it_b - begin(b));
            } else if (it_c != end(c)) {
                res += std::abs(prev_r - 2) + std::abs(prev_c - (it_c - begin(c)));
                prev_r = 2, prev_c = (it_c - begin(c));
            }
        }
        return res;
    }
};