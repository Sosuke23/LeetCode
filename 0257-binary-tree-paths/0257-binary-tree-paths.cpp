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

    void Dfs(TreeNode *root, vector<string> &res, string t) {
        if (!root) {
            return;
        }
        t += to_string(root -> val) + '-' + '>';
        if (root -> left) {
            Dfs(root -> left, res, t);
        }
        if (root -> right) {
            Dfs(root -> right, res, t);
        }
        if (!root -> left and !root -> right) {
            t.pop_back();
            t.pop_back();
            res.push_back(t);
        }
    }

    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string t = "";
        Dfs(root, res, t);
        return res;
    }
};