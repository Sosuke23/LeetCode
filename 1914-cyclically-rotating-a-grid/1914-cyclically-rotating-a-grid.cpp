class Solution {
    pair<int, int> get_pos(int row, int col, int cnt, int loop) {
        int r = loop, c = loop;
        if (cnt < row - 1) {
            return {r + cnt, c};
        } else if ((cnt -= row - 1) < col - 1) {
            return {r + row - 1, c + cnt};
        } else if ((cnt -= col - 1) < row - 1) {
            return {r + row - 1 - cnt, c + col - 1};
        }
        cnt -= row - 1;
        return {r, c + col - 1 - cnt};
    }
    void rotate(vector<vector<int>>& grid, vector<vector<int>>& res, int loop, int row, int col, int k) {
        int size = row * 2 + col * 2 - 4;
        int r = size - k % size;
        for (int l = 0; l < size; l++, r = (r + 1) % size) {
            auto [lr, lc] = get_pos(row, col, l, loop);
            auto [rr, rc] = get_pos(row, col, r, loop);
            res[lr][lc] = grid[rr][rc];
        }
    }
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> res(row, vector<int>(col));
        for (int loop = 0; row && col; ++loop, row -= 2, col -= 2) {
            rotate(grid, res, loop, row, col, k);
        }
        return res;
    }
};