class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<double, unordered_map<double, int>> cnt;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double slope, intercept;
                if (points[i][0] - points[j][0] == 0) {
                    slope = DBL_MAX;
                    intercept = points[i][0];
                } else {
                    int dy = points[i][1] - points[j][1];
                    int dx = (points[i][0] - points[j][0]);
                    slope = 1.0 * dy / dx;
                    intercept =
                        1.0 * (points[i][1] * dx - dy * points[i][0]) / dx;
                }
                cnt[slope][intercept]++;
            }
        }

        int ans = 0;
        for (auto& [slope, m] : cnt) {
            int n_lines = 0;
            for (auto& [intercept, freq] : m) {
                ans += n_lines * freq;
                n_lines += freq;
            }
        }

        map<pair<double, double>, unordered_map<double, int>> midpoints;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double x = (points[i][0] + points[j][0]) / 2.0;
                double y = (points[i][1] + points[j][1]) / 2.0;
                double slope;
                if (points[i][0] - points[j][0] == 0)
                    slope = DBL_MAX;
                else
                    slope = 1.0 * (points[i][1] - points[j][1]) /
                            (points[i][0] - points[j][0]);
                midpoints[{x, y}][slope]++;
            }
        }
        int num_parallelogram = 0;
        for (auto& [mid, m] : midpoints) {
            int n_pairs = 0;
            for (auto& [slope, freq] : m) {
                num_parallelogram += n_pairs * freq;
                n_pairs += freq;
            }
        }

        return ans - num_parallelogram;
    }
};