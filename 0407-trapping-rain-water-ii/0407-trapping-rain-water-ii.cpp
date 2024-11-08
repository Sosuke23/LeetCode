class Solution {
private:
    bool isSafe(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int water = 0; 

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int height = p.first;
            int row = p.second.first;
            int col = p.second.second;

            for (auto& dir : directions) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (isSafe(nextRow, nextCol, n, m) && visited[nextRow][nextCol] == false) {
                    water += max(0, height - heightMap[nextRow][nextCol]);
                    pq.push({max(height, heightMap[nextRow][nextCol]), {nextRow, nextCol}});
                    visited[nextRow][nextCol] = true;
                }
            }
        }
        return water;
    }
};