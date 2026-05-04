class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int res = 0;
        int p = ranks[0];
        int n = (int)ranks.size();

        for (int i = 1; i < n; i++) {
            if (ranks[i] < p) {
                p = ranks[i];
                res++;
            }
        }
        return res;
    }
};