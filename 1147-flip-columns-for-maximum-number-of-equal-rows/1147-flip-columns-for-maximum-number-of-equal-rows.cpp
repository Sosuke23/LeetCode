class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> ump;
        for (auto& x : matrix) {
            int top = x[0];
            string st = "";
            for (int i = 0; i < (int)x.size(); i++) {
                if (x[i] == top) {
                    st += '1';
                } else {
                    st += '0';
                }
            }
            ump[st]++;
        }

        int res = 0;
        for (auto x : ump) {
            res = max(res, x.second);
        }
        return res;
    }
};