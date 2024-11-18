class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        int lo = -1, hi = (int)queries.size() + 1;

        auto f = [&] (int M) {
            std::vector<int> pref(n + 1);
            for (int i = 0; i < std::min(M, (int)queries.size()); i++) {
                std::vector<int> q = queries[i];
                pref[q[0]] += q[2];
                pref[q[1] + 1] -= q[2];
            }

            if (pref[0] < nums[0]) {
                return false;
            }

            for (int i = 1; i < n; i++) {
                pref[i] += pref[i - 1];
                if (pref[i] < nums[i]) {
                    return false;
                }
            }
            return true;
        };

        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (f(mid)) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }

        std::cout << lo << " " << hi << '\n';
        return (lo == (int)queries.size() + 1 ? -1 : lo + 1);
    }
};