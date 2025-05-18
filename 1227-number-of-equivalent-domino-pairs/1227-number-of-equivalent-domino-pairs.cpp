class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        std::map<std::pair<int, int>, int> mp;
        
        for (vector<int> d : dominoes) {
            mp[{std::min(d[0], d[1]), std::max(d[0], d[1])}] += 1;
        }

        int res = 0;
        for (auto [key, val] : mp) {
            val -= 1;
            res += (val * (val + 1)) / 2;
        }
        return res;
    }
};