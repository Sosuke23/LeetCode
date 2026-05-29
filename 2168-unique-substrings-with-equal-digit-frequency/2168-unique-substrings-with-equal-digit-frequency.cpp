class Solution {
public:
    int equalDigitFrequency(string s) {
        int res = 0;
        int n = (int)s.size();
        std::unordered_set<std::string> st;
        for (int i = 0; i < n; i++) {
            std::unordered_map<char, int> mp;
            std::string t = "";
            t += s[i];
            mp[s[i]]++;
            if (st.find(t) == st.end()) {
                st.insert(t);
                res++;
            }
            for (int j = i + 1; j < n; j++) {
                t += s[j];
                mp[s[j]]++;
                if (st.find(t) != st.end()) {
                    continue;
                }
                auto it = mp.begin();
                bool ok = true;
                for (auto [_, val] : mp) {
                    if (val != it->second) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    st.insert(t);
                    res++;
                }
            }
        }
        return res;
    }
};