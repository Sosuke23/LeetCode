class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int p[102] = {0};
        int n = (int)nums.size();
        for (vector<int> v : nums) {
            p[v[0]] += 1;
            p[v[1] + 1] -= 1;
        }
        int res = 0;
        int cnt = 0;
        for (int i = 1; i <= 101; i++) {
            cnt += p[i];
            if (cnt > 0) {
                res += 1;
            }
        }
        return res;
    }
};