class Solution {
public:
    string clearDigits(string s) {
        int n = (int)s.size();
        vector<int> used(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' and s[i] <= '9') {
                int j = i - 1;
                while (j >= 0) {
                    if (s[j] >= 'a' and s[j] <= 'z' and !used[j]) {
                        used[i] = true;
                        used[j] = true;
                        break;
                    }
                    j--;
                }
            }
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                res += s[i];
            }
        }
        return res;
    }
};