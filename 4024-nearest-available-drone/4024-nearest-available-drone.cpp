class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        
        int min_dist = INT_MAX;
        int res = -1;
        int tx = target[0], ty = target[1];
        for (int i = 0; i < (int)drones.size(); i++) {
            int x = drones[i][0], y = drones[i][1], range = drones[i][2];
            int dist = std::abs(x - tx) + std::abs(y - ty);
            if (dist <= range and dist < min_dist) {
                min_dist = dist;
                res = i;
            } 
        }
        return res;
    }
};