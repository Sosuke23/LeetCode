class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        std::unordered_map<std::string, int> cnt;
        std::string st = "";
        for (std::string c : chunks) {
            st += c;
        }

        st += ' ';
        int n = (int)st.size();

        std::string t = "";
        for (int i = 0; i < n; i++) {
            if (st[i] == '-') {
                if (i - 1 >= 0 and (st[i - 1] >= 'a' and st[i - 1] <= 'z') and
                    i + 1 < n and (st[i + 1] >= 'a' and st[i + 1] <= 'z')) {
                        t += st[i];
                    } else {
                        cnt[t]++;
                        t = "";
                    }
            } else if (st[i] == ' ') {
                cnt[t]++;
                t = "";
            } else {
                t += st[i];
            }
        }

        std::vector<int> res;
        for (std::string q : queries) {
            res.push_back(cnt[q]);
        }
        return res;
    }
};