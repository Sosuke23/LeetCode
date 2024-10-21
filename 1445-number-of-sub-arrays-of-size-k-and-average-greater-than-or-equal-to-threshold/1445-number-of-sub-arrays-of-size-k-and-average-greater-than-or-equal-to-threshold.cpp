class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int n = (int)arr.size(), j = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (i >= k - 1) {
                res += (sum / k >= threshold);
                sum -= arr[j];
                j++;
            }
        }
        return res;
    }
};