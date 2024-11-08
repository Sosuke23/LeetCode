class Solution {
public:
    int trap(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> right(n + 1), left(n + 1);
        int res = 0;
        left[0] = arr[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], arr[i]);
        }
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], arr[i]);
        }
        for (int i = 0; i < n; i++) {
            int v = min(left[i], right[i]);
            if (v > arr[i]) {
                res += v - arr[i];
            }
        }
        return res;
    }
};