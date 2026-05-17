class Solution {
public:
    long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
        long long res = 0;
        int n = (int)forward.size() - 1;
        std::vector<long long> pref_f(n + 1, 0), pref_b(n + 1, 0);
        int f = forward.back(), b = backward[0];

        for (int i = 0; i < n; i++) {
            pref_f[i + 1] = pref_f[i] + forward[i];
        }

        for (int i = n; i > 0; i--) {
            pref_b[i - 1] = pref_b[i] + backward[i];
        }

        int from = 0;
        for (int to : queries) {
            long long min_f = 0, min_b = 0;
            if (from < to) {
                min_f = (pref_f[to] - pref_f[from]);
                min_b = (pref_b[0] - pref_b[from]) + (pref_b[to] - pref_b[n]) + b;
            } else {
                min_f = (pref_f[n] - pref_f[from]) + (pref_f[to] - pref_f[0]) + f;
                min_b = (pref_b[to] - pref_b[from]);
            }
            from = to;
            res += std::min(min_f, min_b);
        }


        return res;
    }
};