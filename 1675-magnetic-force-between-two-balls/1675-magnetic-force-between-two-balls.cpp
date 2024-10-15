class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        std::sort(begin(p), end(p));
        int lo = 0, hi = 1e9;

        auto f = [&] (int M) {
            int prev = p[0];
            int cnt = 1;
            for (int i = 1; i < (int)p.size(); i++) {
                if (p[i] - prev >= M) {
                    cnt++;
                    prev = p[i];
                }
                if (cnt >= m) {
                    return true;
                }
            }
            return false;
        };

        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (f(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};