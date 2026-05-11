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

    void dfs(TreeNode* root, std::vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        std::vector<int> res;
        dfs(root, res);

        std::sort(begin(res), end(res), [&] (const auto &a, const auto &b) {
            return std::abs(a - target) <= std::abs(b - target);
        });

        while ((int)res.size() > k) {
            res.pop_back();
        }
        return res;
    }
};