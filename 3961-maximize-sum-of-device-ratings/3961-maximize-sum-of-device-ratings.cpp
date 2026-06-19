class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long res = 0;
        int row = (int)units.size();
        int col = (int)units[0].size();

        if (col == 1) {
            for (std::vector<int> unit : units) {
                res += unit[0];
            }
            return res;
        }

        int minimum = INT_MAX, second_min = INT_MAX;
        for (std::vector<int> unit : units) {
            std::sort(begin(unit), end(unit));

            minimum = std::min(minimum, unit[0]);
            second_min = std::min(second_min, unit[1]);

            res += unit[1];
        }

        res = res - second_min + minimum;
        return res;
    }
};