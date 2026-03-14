class Solution {
public:
    string getHappyString(int n, int k) {
        string res = "";
        vector<char> ch(n);

        auto Dfs = [&](auto Dfs, vector<char>& ch, int ind) {
            if (ind == n) {
                k--;
                return (k == 0);
            }
            if (ind == 0 or ch[ind - 1] != 'a') {
                ch[ind] = 'a';
                if (Dfs(Dfs, ch, ind + 1)) {
                    return true;
                }
            }
            if (ind == 0 or ch[ind - 1] != 'b') {
                ch[ind] = 'b';
                if (Dfs(Dfs, ch, ind + 1)) {
                    return true;
                }
            }
            if (ind == 0 or ch[ind - 1] != 'c') {
                ch[ind] = 'c';
                if (Dfs(Dfs, ch, ind + 1)) {
                    return true;
                }
            }
            return false;
        };
        Dfs(Dfs, ch, 0);

        if (k != 0) {
            return "";
        }
        for (int i = 0; i < n; i++) {
            res += ch[i];
        }
        return res;
    }
};