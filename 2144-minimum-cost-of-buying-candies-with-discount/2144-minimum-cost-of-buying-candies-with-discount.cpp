class Solution {
public:
    int minimumCost(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = 0, n = (int)arr.size();
        for (int i = 0; i < (int)arr.size(); ++i) {
            if (i % 3 != n % 3) {
                res += arr[i];
            }
        }
        return res;
    }
};