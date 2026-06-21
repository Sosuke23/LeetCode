class Solution {
public:
    vector<string> createGrid(int row, int col) {
        std::vector<std::string> res(row, std::string(col, '#'));
        res[0] = std::string(col, '.');
        for (int i = 1; i < row; i++) {
            res[i][col - 1] = '.';
        }

        return res;
    }
};