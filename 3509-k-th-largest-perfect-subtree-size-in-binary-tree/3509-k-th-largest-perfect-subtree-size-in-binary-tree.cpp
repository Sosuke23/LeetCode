/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        std::map<TreeNode*, int> de, sz, cnt;
        vector<int> szs;
        auto dfs = [&](TreeNode* x, auto dfs) -> void {
            sz[x] = 1;
            de[x] = 0;
            if (x->left) {
                dfs(x->left, dfs);
                sz[x] += sz[x->left];
                de[x] = max(de[x], 1 + de[x->left]);
            }
            if (x->right) {
                dfs(x->right, dfs);
                sz[x] += sz[x->right];
                de[x] = max(de[x], 1 + de[x->right]);
            }
            if (sz[x] == ((1 << (de[x] + 1)) - 1)) {
                szs.push_back(sz[x]);
            }
        };
        dfs(root, dfs);
        sort(szs.rbegin(), szs.rend());
        --k;
        if (k < szs.size()) {
            return szs[k];
        }
        return -1;
    }
};