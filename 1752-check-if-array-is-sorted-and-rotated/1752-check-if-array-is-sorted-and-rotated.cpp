class Solution {
public:
    bool check(vector<int>& v) {
        int cnt = 0;
        int n = (int)v.size();
        for (int i = 1; i < n; i++) {
            if (v[i - 1] > v[i]) {
                cnt++;
            }
        }
        if (v[n - 1] > v[0]) {
            cnt++;
        }
        return cnt <= 1;
    }
};