class Solution {
public:
    int largestCombination(vector<int>& a) {
        int res = 0;
        for(int i = 28; i >= 0; --i) {
            int cnt = 0;
            for(int j : a) {
                if(j >> i & 1) {
                    ++cnt;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};