class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        map<long long, int> best;
        sort(a.rbegin(), a.rend());

        int n = (int)a.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            long long x = ((long long)a[i]) * a[i];
            int v = best[x];
            best[a[i]] = v + 1;
            res = max(res, v + 1);
        }
        return (res < 2 ? -1 : res);
    }
};