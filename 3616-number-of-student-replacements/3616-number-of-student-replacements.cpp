class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int res = 0;
        int p = ranks[0];
        int n = (int)ranks.size();
        std::unordered_set<int> uset;
        uset.insert(p);
        for (int i = 1; i < n; i++) {
            if (ranks[i] < p and !uset.count(ranks[i])) {
                res++;
            }
            p = std::min(ranks[i], p);
            uset.insert(p);
        }
        return res;
    }
};