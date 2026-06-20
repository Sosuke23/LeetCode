class Solution {
public:
    int maximumSum(vector<int>& nums) {
        std::sort(rbegin(nums), rend(nums));
        std::unordered_map<int, std::vector<int>> umap;

        for (int x : nums) {
            umap[x % 3].push_back(x);
        }

        int res = 0;
        if (umap[0].size() >= 3) {
            res = umap[0][0] + umap[0][1] + umap[0][2];
        }

        if (umap[2].size() >= 3) {
            res = std::max(res, umap[2][0] + umap[2][1] + umap[2][2]);
        }

        if (umap[1].size() >= 3) {
            res = std::max(res, umap[1][0] + umap[1][1] + umap[1][2]);
        }

        if (umap[0].size() > 0 and umap[1].size() > 0 and umap[2].size() > 0) {
            res = std::max(res, umap[2][0] + umap[1][0] + umap[0][0]);
        }
        return res;
    }
};

/*
max of these {}
0 0 0
2 2 2
1 1 1
0 1 2
*/