class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
	    	unordered_map<float, int> umap;
            for (int j = i + 1; j < n; j++) {
                float slope = 0.0;
                if (points[i][0] - points[j][0] == 0) { // avoid division by 0
                    slope = INT_MAX;
                }
                else {
                    slope = float(points[i][1] - points[j][1]) /
                          float(points[i][0] - points[j][0]);
                }

                umap[slope]++;
            }
            for (auto &[_, slope] : umap) {
                res = max(res, slope);
            }
        }
        return res + 1;
    }
};