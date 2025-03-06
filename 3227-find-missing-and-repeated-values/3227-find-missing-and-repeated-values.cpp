class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        n *= n;
        vector<int> cnt(n, 0);
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[i].size(); j++) {
                cnt[grid[i][j] - 1] += 1;
            }
        }
        
        int a = find(begin(cnt), end(cnt), 0) - begin(cnt);
        int b = find(begin(cnt), end(cnt), 2) - begin(cnt);
        
        return {b + 1, a + 1};
    }
};