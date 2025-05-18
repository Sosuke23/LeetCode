class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = (int)words.size();
        int z = find(begin(groups), end(groups), 0) - begin(groups);
        int o = find(begin(groups), end(groups), 1) - begin(groups);

        vector<int> a, b;
        if (z != -1) {
            int now = 0;
            while (z < (int)groups.size()) {
                if (groups[z] == now) {
                    a.push_back(z);
                    now = (now == 0? 1 : 0);
                }
                z += 1;
            }
        }
        if (o != -1) {
            int now = 1;
            while (o < (int)groups.size()) {
                if (groups[o] == now) {
                    b.push_back(o);
                    now = (now == 0 ? 1 : 0);
                }
                o += 1;
            }
        }

        auto p = b;
        if ((int)a.size() > (int)b.size()) {
            p = a;
        }

        vector<string> res;
        for (auto x : p) {
            res.push_back(words[x]);
        }
        return res;
    }
};