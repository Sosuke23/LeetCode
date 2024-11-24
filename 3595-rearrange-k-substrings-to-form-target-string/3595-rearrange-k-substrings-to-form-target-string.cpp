class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        if (n % k) {
            return 0;
        }
        multiset<string> st;
        int len = n / k;
        for (int i = 0; i < n; i += len) {
            st.insert(s.substr(i, len));
        }
        for (int i = 0; i < n; i += len) {
            string tmp = t.substr(i, len);
            auto it = st.find(tmp);
            if (it == st.end()) {
                return 0;
            }
            st.erase(it);
        }
        return 1;
    }
};