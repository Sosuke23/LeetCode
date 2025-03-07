class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<long long> P;
        vector<bool> PP(right + 1, true);
        for (int i = 2; i <= right; i++) {
            if (PP[i]) {
                P.push_back(i);
                for (int j = 2 * i; j <= right; j += i) {
                    PP[j] = false;
                }
            }
        }
        auto L = upper_bound(P.begin(), P.end(), left - 1) - P.begin();
        int R = L;
        while (R < (int)P.size()) {
            if (P[R] <= right) {
                R += 1;
                continue;
            }
            else {
                R -= 1;
                break;
            }
            R += 1;
        }
        if (R >= (int)P.size()) {
            R -= 1;
        }
        if (R - L + 1 < 2) {
            return {-1, -1};
        }
        int mn = INT_MAX;
        vector<int> res(2);
        for (int i = L; i < R; i++) {
            if (P[i + 1] - P[i] < mn) {
                mn = P[i + 1] - P[i];
                res[0] = P[i], res[1] = P[i + 1];
            }
        }
        return res;
    }
};