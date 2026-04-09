class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        
        int max_quality_factor = INT_MIN;
        int max_x = -1, max_y = -1;
        for (std::vector<int> t : towers) {
            int dis = std::abs(center[0] - t[0]) + std::abs(center[1] - t[1]);
            if (dis <= radius) {
                if (t[2] > max_quality_factor) {
                    max_quality_factor = t[2];
                    max_x = t[0], max_y = t[1];
                } else if (t[2] == max_quality_factor) {
                    if (t[0] < max_x) {
                        max_x = t[0], max_y = t[1];
                    } else if (t[0] == max_x and t[1] < max_y) {
                        max_x = t[0], max_y = t[1];
                    }
                }
            }
        }
        return {max_x, max_y};
    }
};