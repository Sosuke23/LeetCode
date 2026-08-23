class Solution {
public:
    bool isPalindromic(string s) {
        std::string final_string = "";
        for (char c : s) {
            int ascii_value = c;
            bitset<8> b(ascii_value);
            final_string += b.to_string();
        }

        auto is_palin = [] (std::string p) {
            int n = (int)p.size();
            for (int i = 0; i < n / 2; i++) {
                if (p[i] != p[n - i - 1]) {
                    return false;
                }
            }
            return true;
        };

        return is_palin(final_string);
    }
};