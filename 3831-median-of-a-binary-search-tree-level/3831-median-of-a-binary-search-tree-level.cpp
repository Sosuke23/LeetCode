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
    int lvl = 0;
    std::vector<int> ele;
    void dfs(TreeNode* root, int cnt) {
        if (root == nullptr) {
            return;
        }
        if (cnt == lvl) {
            ele.push_back(root->val);
        }

        cnt++;
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }

    int levelMedian(TreeNode* root, int level) {
        lvl = level;
        dfs(root, 0);
        if (ele.empty()) {
            return -1;
        }
        std::sort(begin(ele), end(ele));
        return ele[(int)ele.size() / 2];
    }
};