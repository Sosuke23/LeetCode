class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        int n = (int)energy.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                energy[i] += energy[i + k];
            }
            res = max(res, energy[i]);
        }
        return res;
    }
};