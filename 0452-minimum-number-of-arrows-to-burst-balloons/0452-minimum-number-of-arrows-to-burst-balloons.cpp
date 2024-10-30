class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [&] (const vector<int> &i, const vector<int> &j) {
            return i[1] < j[1];
        });

        int prev = points[0][1];
        int res = 0;
        for (int i = 1; i < (int)points.size(); i++) {
            if (points[i][0] > prev) {
                res += 1;
                prev = points[i][1];
            }
        }
        return res + 1;
    }
};