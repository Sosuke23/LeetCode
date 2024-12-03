class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int pos = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (pos < (int)spaces.size()) {
                if (i == spaces[pos]) {
                    res += " ";
                    pos += 1;
                }
            }
            res += s[i];
        }
        return res;
    }
};