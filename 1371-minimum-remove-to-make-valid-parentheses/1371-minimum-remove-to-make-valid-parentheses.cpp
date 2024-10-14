class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = (int)s.size();
        std::vector<int> vis(n, 0);
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open += 1;
            } else if (s[i] == ')') {
                if (open > 0) {
                    open -= 1;
                } else {
                    vis[i] = 1;
                }
            } 
        }
        if (open > 0) {
            while (open > 0) {
                for (int i = n - 1; i >= 0; i--) {
                    if (s[i] == '(') {
                        vis[i] = 1;
                        open -= 1;
                    }
                    if (open == 0) {
                        break;
                    }
                }
            }
        }
        std::string res = "";
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            res += s[i];
        }
        return res;
    }
};