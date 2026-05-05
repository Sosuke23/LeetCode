class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        std::unordered_map<int, int> umap;
        for (int i = n - 1; i >= 0; i--) {
            umap[nums1[i]] = i;
        }

        int res = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (umap.count(nums2[i])) {
                res = std::min(res, umap[nums2[i]] + i);
            }
        }

        return (res == INT_MAX ? -1 : res);
    }
};