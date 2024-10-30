class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int range[1002] = {0};
        for (vector<int> t : trips) {
            range[t[1]] += t[0];
            range[t[2]] -= t[0];
        }

        int c = 0;
        for (int i = 0; i <= 1000; i++) {
            c += range[i];
            if (c > capacity) {
                return false;
            }
        }
        return true;
    }
};