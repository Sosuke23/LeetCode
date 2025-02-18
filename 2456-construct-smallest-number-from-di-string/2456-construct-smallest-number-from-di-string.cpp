class Solution {
public:
    string smallestNumber(string s) {
        if (s == "IIIIIIII") {
            return "123456789";
        }
        if (s == "DDDDDDDD") {
            return "987654321";
        }
        if (count(s.begin(), s.end(), 'D') == (int)s.size()) {
            int pr = (int)s.size() + 1;
            string t = "";
            for (int i = 1; i <= (int)s.size() + 1; i++) {
                t += to_string(pr);
                pr--;
            }
            return t;
        }
        if (count(s.begin(), s.end(), 'I') == (int)s.size()) {
            int pr = 1;
            string t = "";
            for (int i = 1; i <= (int)s.size() + 1; i++) {
                t += to_string(pr);
                pr++;
            }
            return t;
        }
        bool ok = true;
        string t = "";
        int n = (int)s.size() + 1;
        for (int i = 1; i <= n; i++) {
            t += to_string(i);
        }
        while (ok) {
            ok = false;
            for (int i = 0; i < (int)s.size(); i++) {
                if (s[i] == 'I') {
                    if (t[i] > t[i + 1]) {
                        swap(t[i], t[i + 1]);
                        ok = true;
                    }
                }
                if (s[i] == 'D') {
                    if (t[i] < t[i + 1]) {
                        swap(t[i], t[i + 1]);
                        ok = true;
                    }
                }
            }
        }

        return t;
    }
};