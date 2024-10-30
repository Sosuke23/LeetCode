class Solution {
public:
    int minimumMountainRemovals(vector<int>& Arr) {
        int n = (int)Arr.size();
        auto Longest_Bitonic_Subsequence = [&] () {
            vector<int> LIS(n + 4, 1), LDS(n + 4, 1);
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (Arr[i] > Arr[j] and LIS[i] < LIS[j] + 1) {
                        LIS[i] = LIS[j] + 1;
                    }
                }
            }

            for (int i = n - 2; i >= 0; i--) {
                for (int j = n - 1; j > i; j--) {
                    if (Arr[i] > Arr[j] and LDS[i] < LDS[j] + 1) {
                        LDS[i] = LDS[j] + 1;
                    }
                }
            }

            int res = 0;
            for (int i = 0; i < n; i++) {
                if (LIS[i] > 1 and LDS[i] > 1) {
                    res = max(res, LIS[i] + LDS[i] - 1);
                }
            }
            return res;
        };

        return n - Longest_Bitonic_Subsequence();
    }
};