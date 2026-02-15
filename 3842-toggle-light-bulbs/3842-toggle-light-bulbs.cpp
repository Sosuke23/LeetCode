class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        std::map<int, int> mp;
        for (auto x : bulbs) {
            mp[x]++;
        } 

        std::vector<int> res;
        for (auto x : mp) {
            if (x.second % 2 == 1) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};