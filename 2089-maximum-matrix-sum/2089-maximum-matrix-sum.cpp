class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        typedef long long i23;
        vector<int> Arr;
        int neg = 0;
        i23 res = 0;
        for (auto x : matrix) {
            for (auto y : x) {
                neg += (y < 0);
                Arr.push_back(abs(y));
                res += Arr.back();
            }
        }

        sort(begin(Arr), end(Arr));
        if (neg & 1) {
            res -= 2 * Arr[0];
        }
        return res;
    }
};