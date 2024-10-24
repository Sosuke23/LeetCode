class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> arr;
        s += ' ';
        std::string t = "";
        for (auto x : s) {
            if (x == ' ') {
                if (!t.empty()) {
                    arr.push_back(t);
                }
                t = "";
                continue;
            } else {
                t += x;
            }
        }
        std::string res = "";
        for (int i = (int)arr.size() - 1; i >= 0; i--) {
            res += arr[i];
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};