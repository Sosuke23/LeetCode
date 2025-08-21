/**
 * dp[r][c][w] stands for the maximum height of the submatrices
 *             whose right-bottom corner is `mat[r - 1][c - 1]`, and
 *             whose width is `w`,
 *             where `r` is in the range [0, `row`], both inclusive
 *                   `c` is in the range [0, `cols`], both inclusive
 *                   `w` is in the range [0, `c`], both inclusive
 *
 * initial:
 * dp[r][c][w] = 0, where `r` is 0, `c` is 0
 *
 * induction:
 * if mat[r][c] is not equal to 1, do nothing,
 * otherwise, perform the following logic,
 *   1. if `w` == 1
 *      dp[r + 1][c + 1][w] = 1 + dp[r][c + 1][w]
 *   2. otherwise
 *      dp[r + 1][c + 1][w] = min(dp[r + 1][c][w - 1], 1 + dp[r][c + 1][w])
 * where `r` in the range [1, `rows`], both inclusive
 *       `c` in the range [1, `cols`], both inclusive
 *       `w` in the range [1, `c`], both inclusive
 *
 * target:
 * sum(dp[r][c][w] for all possible combinations of `r`, `c`, and `w`)
 *
 * Time Complexity: O(rows * cols * cols)
 * Space Complexity: O(rows * cols * cols)
 * where `rows` is the number of the rows of the matrix `mat`
 *       `cols` is the number of the columns of the matrix `mat`
 */
class Solution {
 public:
  int numSubmat(const vector<vector<int>> &mat) {
    constexpr int target = 1;
    const int rows = static_cast<int>(mat.size());
    const int cols = static_cast<int>(mat.front().size());
    int ret = 0;
    int dp[rows + 1][cols + 1][cols + 1];
    memset(dp, 0, sizeof(dp));
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (mat[r][c] != target) {
          continue;
        }
        
        for (int w = 1; w <= c + 1; ++w) {
          if (w == 1) {
            dp[r + 1][c + 1][w] = 1 + dp[r][c + 1][w];
          } else {
            dp[r + 1][c + 1][w] = min(dp[r + 1][c][w - 1], 1 + dp[r][c + 1][w]);
          }
          ret += dp[r + 1][c + 1][w];
        }
      }
    }
    return ret;
  }
};