class Solution {
public:
    int maxDistance(vector<string>& words) {
        int res = 0;
        for (int i = 1; i < (int)words.size(); i++) {
            if (words[i] != words[0]) {
                res = i + 1;
            }
        }

        for (int i = (int)words.size() - 1; i > 0; i--) {
            if (words[i] != words.back()) {
                res = std::max(res,  (int)words.size() - i);
            }
        }
        return res;
    }
};