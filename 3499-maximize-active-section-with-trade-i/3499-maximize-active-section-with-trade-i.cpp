class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i = 0, n = (int)s.length();
        int ans = 0, prevZero = 0, ones = 0;
        while (i < n) {
            if (s[i] == '1') {
                ones++;
                i++;
                continue;
            }
            int z = 0;
            while (i < n && s[i] == '0') {
                z++;
                i++;
            }

            if (prevZero > 0) {
                ans = max(ans, prevZero + z);
            }

            prevZero = z;
        }

        return ans + ones;
    }
};