class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int res = -1;
        int n = (int)nums.size();
        std::unordered_map<int, int> umap;
        for (int i = 0; i <= n - k; i++) {
            std::unordered_set<int> uset;
            for (int j = 0; j < k; j++) {
                if (uset.find(nums[i + j]) == uset.end()) {
                    umap[nums[i + j]]++;
                    uset.insert(nums[i + j]);
                }
                
            }
        }

        for (auto [key, val] : umap) {
            if (val == 1) {
                res = std::max(res, key);
            } 
        }
        return res;
    }
};