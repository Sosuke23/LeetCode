class Solution {
public:
    bool detectCapitalUse(string w) {
        int n = (int)w.size();
        int a = 0, b = 0, c = 0;
        for (auto x : w) {
            if (isupper(x))
                a++;
        }
        char t = w.front();
        if (isupper(t) and a == 1)
            return true;
        else if (a == n || a == 0)
            return true;
        else
            return false;
    }
};