class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int p[101] = {0};
        int n = (int)nums.size();
        for (vector<int> v : nums) {
            for (int i = v[0]; i <= v[1]; i++) {
                p[i] = 1;
            }
        }
        int res = count(p + 1, p + 101, 1);
        return res;
    }
};