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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root == NULL) {return res;}
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int p = INT_MIN;
            for (int i = 0; i < n; i++) {
                TreeNode* s = q.front();
                p = max(p, s->val);
                q.pop();
                if (s->left) {
                    q.push(s->left);
                }
                if (s->right) {
                    q.push(s->right);
                }
            }
            res.push_back(p);
        }
        return res;
    }
};