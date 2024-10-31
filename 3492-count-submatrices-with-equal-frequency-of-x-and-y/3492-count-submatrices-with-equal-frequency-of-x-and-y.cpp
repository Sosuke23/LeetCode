#include <bits/stdc++.h>
using namespace std;
#ifdef freakin23
#include "library/debug.cpp"
#else
#define debug(...)
#endif

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> pref_x(rows + 4, vector<int>(cols + 4, 0));
        vector<vector<int>> pref_y(rows + 4, vector<int>(cols + 4, 0));

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                pref_x[i][j] = pref_x[i-1][j] + pref_x[i][j-1] - pref_x[i-1][j-1] + (grid[i-1][j-1] == 'X' ? 1 : 0);
                pref_y[i][j] = pref_y[i-1][j] + pref_y[i][j-1] - pref_y[i-1][j-1] + (grid[i-1][j-1] == 'Y' ? 1 : 0);
            }
        }

        int res = 0;

        for (int i = 0; i < 1; i++) {
            for (int j = 0; j < 1; j++) {
                for (int k = i; k < rows; k++) {
                    for (int l = j; l < cols; l++) {
                        int cnt_x = pref_x[k + 1][l + 1] - pref_x[i][l + 1] - pref_x[k + 1][j] + pref_x[i][j];
                        int cnt_y = pref_y[k + 1][l + 1] - pref_y[i][l + 1] - pref_y[k + 1][j] + pref_y[i][j];
                        res += (cnt_x > 0 and cnt_x == cnt_y);
                    }
                }
            }
        }

        return res;
    }
};

#ifdef freakin23
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}
#endif