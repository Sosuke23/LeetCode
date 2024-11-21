class Solution {
public:

    void Solve(vector<vector<int>> &G, int i, int j, int dir) {
        if (i < 0 or j < 0 or i >= (int)G.size() or j >= (int)G[0].size()) {
            return;
        }
        if (G[i][j] == -1 or G[i][j] == 1) {
            return;
        }
        G[i][j] = 2;
        if (dir == 1) {
            Solve(G, i + 1, j, 1);
        }
        else if (dir == 2) {
            Solve(G, i - 1, j, 2);
        }
        else if (dir == 3) {
            Solve(G, i, j + 1, 3);
        }
        else {
            Solve(G, i, j - 1, 4);
        }
        
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> G(m, vector<int> (n, 0));
        for (auto x : guards) {
            G[x[0]][x[1]] = 1;
        }   
        for (auto x : walls) {
            G[x[0]][x[1]] = -1;
        }
        for (int i = 0; i < (int)guards.size(); i++) {
            int x = guards[i][0], y = guards[i][1];
            if (G[x][y]) {
                Solve(G, x + 1, y, 1);
                Solve(G, x - 1, y, 2);
                Solve(G, x, y + 1, 3);
                Solve(G, x, y - 1, 4);
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += (G[i][j] == 0);
            }
        }
        return res;
    }
};