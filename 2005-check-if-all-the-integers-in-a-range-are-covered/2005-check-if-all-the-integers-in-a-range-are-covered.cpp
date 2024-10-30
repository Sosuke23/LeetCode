class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int range[52] = {0};
        for (vector<int> r : ranges) {
            range[r[0]] += 1;
            range[r[1] + 1] -= 1;
        }

        int overlap = 0;
        for (int i = 1; i <= 51; i++) {
            overlap += range[i];
            if (i >= left and i <= right and overlap <= 0) {
                return false;
            }
        }
        return true;
    }
};