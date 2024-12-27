class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& a) {
        int n = a.size();
        vector<int> v(n, INT_MIN);
        v[n - 1] = a[n - 1] - (n - 1);
        for (int i = n - 2; i >= 0; i--) {
            v[i] = max(v[i + 1], a[i] - i);
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            res = max(res, a[i] + i + v[i + 1]);
        }
        return res;
    }
};