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
    int n;
    bool check(TreeNode* root, vector<int>& arr, int pos) {
        if (root == nullptr) {
            return false;
        }
        if (arr[pos] != root->val) {
            return false;
        }
        if (pos == n - 1) {
            return !root->right && !root->left;
        }
        return check(root->right, arr, pos + 1) || check(root->left, arr, pos + 1);
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n = (int)arr.size();
        return check(root, arr, 0);
    }
};