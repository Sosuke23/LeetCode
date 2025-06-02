class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = (int)ratings.size();
        vector<int> P(n);
        P[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                P[i] = P[i - 1] + 1;
            }
            else {
                P[i] = 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                P[i] = max(P[i], P[i + 1] + 1);
            }
        }

        int res = 0;
        for (auto x : P) {
            res += x;
        }
        return res;
    }
};