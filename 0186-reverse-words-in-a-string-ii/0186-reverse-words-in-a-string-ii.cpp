class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        std::reverse(begin(s), end(s));
        s.push_back(' ');
        std::vector<int> pos;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                pos.push_back(i);
            }
        }

        int prev = 0;
        for (int p : pos) {
            std::reverse(begin(s) + prev, begin(s) + p);
            prev = p + 1;
        }
        s.pop_back();
    }
};