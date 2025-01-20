class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int n = (int)mat.size(), m = (int)mat[0].size();
        std::map<int, std::pair<int, int>> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]] = make_pair(i, j);
            }
        }

        std::vector<int> row[100001], col[100001];
        for (int i = 0; i < (int)arr.size(); i++) {
            int r = pos[arr[i]].first;
            int c = pos[arr[i]].second;

            row[r].push_back(c);
            col[c].push_back(r);

            if (row[r].size() == m or col[c].size() == n) {
                return i;
            }
        }
        return (int)arr.size() - 1;
    }
};