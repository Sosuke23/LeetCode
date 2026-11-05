class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int ans = 0;
        for (auto x : a) {
            bool ok = true;
            for (auto y : b) {
                if (abs(x - y) <= d) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
        return ans;
    }
};