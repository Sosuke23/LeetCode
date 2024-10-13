class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::vector<int> idx;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                idx.push_back(i);
            } else if (s[i] == ')') {
                std::reverse(begin(s) + idx.back(), begin(s) + (i + 1));
                idx.pop_back();
            }
        }
        std::string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' and s[i] <= 'z') {
                res += s[i];
            }
        }
        return res;
    }
};