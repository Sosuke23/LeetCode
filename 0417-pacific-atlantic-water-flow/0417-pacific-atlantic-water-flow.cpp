class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            dfs(pac, heights, heights[i][0], i, 0);
            dfs(atl, heights, heights[i][n-1], i, n-1);
        }
        for(int j = 0; j < n; j++){
            dfs(pac, heights, heights[0][j], 0, j);
            dfs(atl, heights, heights[m-1][j], m-1, j);
        }
        vector<vector<int>> result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pac[i][j] && atl[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
    void dfs(vector<vector<int>> & visited, vector<vector<int>> & heights, int prevheight, int i, int j){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[i][j] || prevheight > heights[i][j]){
            return;
        }
        else{
            visited[i][j] = 1;
            dfs(visited, heights, heights[i][j], i+1, j);
            dfs(visited, heights, heights[i][j], i-1, j);
            dfs(visited, heights, heights[i][j], i, j+1);
            dfs(visited, heights, heights[i][j], i, j-1);
            return;
        }
    }
};