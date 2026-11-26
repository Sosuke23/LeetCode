class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int x = 0, y = 0;
        int row = (int)grid.size(), col = (int)grid[0].size();

        std::unordered_map<std::string, int> visited;
        
        std::string curr = std::to_string(x) + '$' + std::to_string(y);
        int prev_x = x, prev_y = y;
        while (visited.find(curr) == visited.end()) {
            visited[curr] = 1;
            char nxt = grid[x][y];
            prev_x = x, prev_y = y;
            if (nxt == 'R') {
                y += 1;
            } else if (nxt == 'L') {
                y -= 1;
            } else if (nxt == 'D') {
                x += 1;
            } else if (nxt == 'U') {
                x -= 1;
            }

            if (x < 0 or y < 0 or x >= row or y >= col) {
                break;
            }
            curr = std::to_string(x) + '$' + std::to_string(y);
        }
        return {prev_x, prev_y};
    }
};