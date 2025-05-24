class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < (int)words.size(); i++) {
            if (count(begin(words[i]),end(words[i]), x)) {
                res.push_back(i);
            }
        }
        return res;
    }
};