class Solution {
public:
    unordered_map<float, int> umap;
    int maxPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float key = 0.0;
                if (points[i][0] - points[j][0] == 0) { // avoid division by 0
                    key = INT_MAX;
                }
                else {
                    key = float(points[i][1] - points[j][1]) /
                          float(points[i][0] - points[j][0]);
                }

                umap[key]++;
            }
            for (auto &[_, key] : umap) {
                res = max(res, key);
            }
            umap.clear();
        }
        return res + 1;
    }
};