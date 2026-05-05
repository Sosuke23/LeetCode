class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        std::unordered_map<int, std::vector<std::pair<int, int>>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums1[i]].push_back({i, 1});
        }
        for (int i = 0; i < n; i++) {
            pos[nums2[i]].push_back({i, 2});
        }

        int res = INT_MAX;
        for (auto &[_, val] : pos) {
            std::sort(begin(val), end(val));
            int prev = val[0].second;
            int prev_i = val[0].first;
            for (int i = 1; i < (int)val.size(); i++) {
                if (prev != val[i].second) {
                    res = std::min(res, prev_i + val[i].first);
                    prev_i = val[i].first;
                    prev = val[i].second;
                }
            }
        }
        return (res == INT_MAX ? -1 : res);
    }
};