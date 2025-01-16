class Solution {
public:
    int xorAllNums(vector<int>& a, vector<int>& b) {
        int res = 0;
        if (a.size() % 2) {
            for (auto x : b) {
                res ^= x;
            }
        }
        if (b.size() % 2) {
            for (auto x : a) {
                res ^= x;
            }
        }
        return res;
    }
};