class Solution {
public:
    bool hasSameDigits(string s) {
        while ((int)s.size() > 2) {
            std::string a = "";
            for (int i = 0; i < (int)s.size() - 1; i++) {
                a += std::to_string(((s[i] - '0') + (s[i + 1] - '0')) % 10);
            }
            s = a;
        }

        return (s[0] == s[1]);
    }
}; 