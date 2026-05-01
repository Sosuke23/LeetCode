class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        std::map<int, std::set<int>> mp;
        for (std::vector<int> s : students) {
            mp[s[1]].insert(s[0]);
        }

        int res = 0;
        for (auto &[_, un] : mp) {
            res = std::max(res, (int)un.size());
        }

        return res;
    }
};