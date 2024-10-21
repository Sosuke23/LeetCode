class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {{""}};
        }
        std::vector<std::vector<std::string>> res;
        std::map<std::string, std::vector<std::string>> mp;
        for (auto x : strs) {
            std::string t = x;
            std::sort(begin(t), end(t));
            mp[t].push_back(x);
        }

        for (auto &[_, r] : mp) {
            res.push_back(r);
        }
        return res;
    }
};