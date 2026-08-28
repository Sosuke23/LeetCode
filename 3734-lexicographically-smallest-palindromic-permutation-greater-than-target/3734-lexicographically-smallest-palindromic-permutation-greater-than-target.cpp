class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> cnt(26, 0);
        for(char c : s) cnt[c - 'a']++;
        
        int odd_c = 0;
        char mid = 0;
        vector<int> half(26, 0);
        
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                odd_c++;
                mid = i + 'a';
            }
            half[i] = cnt[i] / 2;
        }
        
        if(odd_c > 1) return "";
        
        string fh = "", ans = "";
        bool found = false;
        int hl = n / 2;
        
        auto build = [&](string h) {
            string res = h;
            if(n % 2) res += mid;
            reverse(h.begin(), h.end());
            res += h;
            return res;
        };
        
        auto dfs = [&](auto& self, int idx, bool greater) -> void {
            if(found) return;
            if(idx == hl) {
                string full = build(fh);
                if(full > target) {
                    ans = full;
                    found = true;
                }
                return;
            }
            for(int i = 0; i < 26; i++) {
                if(half[i] > 0) {
                    char c = i + 'a';
                    if(!greater && c < target[idx]) continue;
                    half[i]--;
                    fh.push_back(c);
                    self(self, idx + 1, greater || (c > target[idx]));
                    if(found) return;
                    fh.pop_back();
                    half[i]++;
                }
            }
        };
        
        dfs(dfs, 0, false);
        return ans;
    }
};