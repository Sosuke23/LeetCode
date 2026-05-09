/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;

    long dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long left = dfs(root->left);
        long right = dfs(root->right);

        if (left + right == root->val) {
            res++;
        }

        return left + right + root->val;

    }

    int equalToDescendants(TreeNode* root) {
        dfs(root);
        return res;
    }
};