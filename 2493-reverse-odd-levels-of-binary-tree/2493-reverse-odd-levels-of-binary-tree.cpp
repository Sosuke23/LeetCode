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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool level = false;
        queue<TreeNode*> lvl_nd;

        stack<int> lvl_dat;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                if (level) {
                    lvl_nd.push(curr);
                    lvl_dat.push(curr->val);
                }

                if (n == 0) {

                    level = !level;
                    while (!lvl_nd.empty()) {
                        TreeNode* front = lvl_nd.front();
                        front->val = lvl_dat.top();

                        lvl_nd.pop();
                        lvl_dat.pop();
                    }
                }
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};