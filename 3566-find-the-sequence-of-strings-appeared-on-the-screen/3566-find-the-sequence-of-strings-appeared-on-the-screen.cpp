class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string screen = "";
        for (int i = 0; i < target.size(); ++i) {
            while (screen.size() < i + 1) {
                screen += 'a';
                res.push_back(screen);
            }
            while (screen.back() != target[i]) {
                screen.back() = screen.back() == 'z' ? 'a' : screen.back() + 1;
                res.push_back(screen);
            }
        }
        return res;
    }
};