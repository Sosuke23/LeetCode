class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        std::vector<std::vector<int>> res(n, std::vector<int> (m, 0));
        std::sort(begin(sources), end(sources), [&] (const auto &a, const auto &b) {
            return a[2] > b[2];
        });

        for (auto x : sources) {
            res[x[0]][x[1]] = x[2];
        }

        if (sources.front()[2] == sources.back()[2]) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = sources.back()[2];
                }
            }
            return res;
        }
                
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, -1, 1};

        while (!sources.empty()) {
            std::vector<std::vector<int>> temp_sources;
            for (int i = 0; i < sources.size(); i++) {
                int row, col, colour;
                row = sources[i][0], col = sources[i][1], colour = sources[i][2]; 
                // sources.pop_back();
                
                for (int i = 0; i < 4; i++) {
                    int new_row = row + dx[i];
                    int new_col = col + dy[i];

                    if (new_row >= 0 and new_row < n and new_col >= 0 and new_col < m and res[new_row][new_col] == 0) {
                        temp_sources.push_back({new_row, new_col, colour});
                        // std::cout << row << " " << col << ": " << new_row << " " << new_col << ": " << colour << '\n';
                        res[new_row][new_col] = colour;
                    }
                }
            }
            sources = temp_sources;
            // reverse(begin(sources), end(sources));
        }
        return res;
    }
};