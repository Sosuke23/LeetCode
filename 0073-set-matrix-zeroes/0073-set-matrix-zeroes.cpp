class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = (int)matrix.size();
        int col = (int)matrix[0].size();
        auto A = matrix;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < i; k++) {
                        A[k][j] = 0;
                    }
                    for (int k = i + 1; k < row; k++) {
                        A[k][j] = 0;
                    }
                    for (int k = 0; k < j; k++) {
                        A[i][k] = 0;
                    }
                    for (int k = j + 1; k < col; k++) {
                        A[i][k] = 0;
                    }
                }
            }
        }
        matrix = A;
    }
};