class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = (int)s.size();
        int no = (int)order.size();

        if (n == 1) {
            if (k <= 1) {
                return 0;
            }
            return -1;
        }

        long long can = 1LL * n * (n + 1) / 2;
        if (k > can) {
            return -1;
        }

        auto f = [&] (int mid) {
            std::string t = s;
            for (int i = 0; i < std::min(no, mid); i++) {
                t[order[i]] = '*';
            }

            long long seg_len = 0, invalid_cnt = 0;
            for (int i = 0; i < n; i++) {
                if (t[i] == '*') {
                    invalid_cnt += seg_len * (seg_len + 1) / 2;
                    seg_len = 0;
                } else {
                    seg_len++;
                }
            }

            if (seg_len) {
                invalid_cnt += seg_len * (seg_len + 1) / 2;
            }

            return (can - invalid_cnt >= k);
        };

        long long lo = 0, hi = n;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (f(mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        std::cout << lo << " " << hi << '\n';
        return hi;
    }
};