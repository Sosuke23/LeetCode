class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        std::sort(begin(intervals), end(intervals));
        int start = intervals[0][0], end = intervals[0][1];
        int total = 0;
        for (std::vector<int> interval : intervals) {
            if (interval[0] <= end) {
                end = std::max(end, interval[1]);
            } else {
                total += end - start + 1;
                start = interval[0];
                end = interval[1];
            }
        }

        total += end - start + 1;
        int req = (brightness + 2) / 3;
        return 1LL * req * total;
    }
};