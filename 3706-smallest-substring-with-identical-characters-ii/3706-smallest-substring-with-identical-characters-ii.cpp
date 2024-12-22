class Solution {
public:
    int minLength(string s, int numOps) {
        int cnt = 0, cnt2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] - '0') == i % 2) {
                cnt++;
            }
            else {
                cnt2++;
            }
        }
        if (cnt <= numOps || cnt2 <= numOps) {
            return 1;
        }
        int lo = 1, hi = s.size();
        while (lo + 1 < hi) {
            int mid = (hi + lo) / 2;
            int last = s[0], cnt = 0;
            int tot = 0;
            for (auto it : s) {
                if (it == last) {
                    cnt++;
                }
                else {
                    last = it, cnt = 1;
                }
                if (cnt > mid) {
                    tot++, cnt = 0;
                }
            }
            if (tot > numOps) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        return hi;
    }
};