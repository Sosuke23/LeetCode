class Solution {
public:
    bool checkString(string s) {
        string t = s;
        reverse(begin(t), end(t));

        int b = s.find('b');
        int a = t.find('a');
        if (a == -1) {
            return true;
        }
        if (b == -1) {
            return true;
        }
        a = (int)s.size() - a - 1;
        return (a < b ? true : false);
    }
};