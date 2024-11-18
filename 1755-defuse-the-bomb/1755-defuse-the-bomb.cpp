class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = (int)code.size();
        vector<int> res(n, 0);

        if (k == 0) {
            return res;
        }
        vector<int> pref(n +  1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = code[i] + pref[i];
        }

        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int rem = n - i - 1;
                int right = 0, left = 0;
                if (rem >= k) {
                    right += pref[k + i + 1] - pref[i + 1];
                    res[i] = right;
                }
                else {
                    right += pref[n] - pref[i + 1];
                    left += pref[k - (n - (i + 1))] - pref[0];
                    res[i] = right + left;
                }
            }
        }

        if (k < 0) {
            k = abs(k);
            for (int i = 0; i < n; i++) {
                int l_rem = i;
                int right = 0, left = 0;
                if (l_rem >= k) {
                    left += pref[i] - pref[i - k];
                    res[i] = left;
                }
                else {
                    right += pref[i];
                    left += pref[n] - pref[n - (k - i)];
                    res[i] = left + right;
                }
            }
        }

        return res;
    }
};