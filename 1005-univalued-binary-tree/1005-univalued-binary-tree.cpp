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

std::unordered_set<int> uset;
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        uset.insert(root->val);
        if (root->left) {
            dfs(root->left);
        }
        if (root->right) {
            dfs(root->right);
        }
    }

    bool isUnivalTree(TreeNode* root) {
        dfs(root);
        return ((int)uset.size() == 1);
    }
};