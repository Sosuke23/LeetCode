class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        map<int, int> color, mp;
        set<int> vis;
        for (int i = 0; i < (int)queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            if (!vis.count(x)) {
                vis.insert(x);
                mp[x] = y;
                color[y]++;
            } else {
                color[mp[x]]--;
                if (color[mp[x]] == 0) {
                    color.erase(mp[x]);
                }
                color[y]++;
                mp[x] = y;
            }
            res.push_back((int)color.size());
        }
        return res;
    }
};