class Solution {
public:
    int maxDistance(vector<string>& words) {
        int res = 0;
        int n = (int)words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i] != words[j]) {
                    res = std::max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};