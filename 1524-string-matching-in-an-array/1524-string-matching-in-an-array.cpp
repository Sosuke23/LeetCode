class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        int n = (int)words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (words[i].find(words[j]) != -1) {
                        if (find(begin(res), end(res), words[j]) != end(res)) {
                            continue;
                        } else {
                            res.push_back(words[j]);
                        }
                    }
                }
            }
        }
        return res;
    }
};