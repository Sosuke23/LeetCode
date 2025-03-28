class Solution {
    int fact(int n) {
        int f = 1;
        for(int i=1; i<=n; i++) {
            f *= i;
        } 
        return f;
    }
    void dfs(int i, string &t, string &s, unordered_set<string> &st) {
        if(i == t.size()) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            st.insert(tmp);
            return;
        }
        dfs(i + 1, t, s, st);
        s += t[i];
        dfs(i + 1, t, s, st);
        s.pop_back();
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        string s;
        int res = 0;
        dfs(0, tiles, s, st);

        for(string str : st) {
            int n = fact(str.size());
            unordered_map<char, int> m;
            for(char c : str) {
                m[c]++;
            }
            for(auto i : m) {
                n /= fact(i.second);
            } 
            res += n;
        }
        return res - 1; 
    }
};