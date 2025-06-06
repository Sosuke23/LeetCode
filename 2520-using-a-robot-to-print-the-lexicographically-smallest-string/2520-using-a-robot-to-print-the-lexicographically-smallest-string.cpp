class Solution {
public:
    string robotWithString(string s) {
        vector<int> cnt(26, 0);
        for (auto ch : s) {
            cnt[ch - 'a']++;
        }
        string t = "", ans = "";
        for (char ch : s) {
            int small = -1;
            for (int j = 0; j <= ch - 'a'; j++) {
                if (cnt[j] > 0) {
                    small = j;
                    break;
                }
            }
            cnt[ch - 'a']--;
            if (small < ch - 'a') {
                while (t.size() && t.back() - 'a' <= small) {
                    ans += t.back(), t.pop_back();
                }
                t += ch;
            } else {
                while (t.size() && t.back() - 'a' <= small) {
                    ans += t.back(), t.pop_back();
                }
                ans += ch;
            }
        }
        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};