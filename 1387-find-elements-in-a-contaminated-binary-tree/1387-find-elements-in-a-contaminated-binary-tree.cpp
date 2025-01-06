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
class FindElements {
public:
std::unordered_set<int> u_set;

    void dfs(TreeNode* root, int prev) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            u_set.insert(2 * prev + 1);
            dfs(root->left, 2 * prev + 1);
        }
        if (root->right) {
            u_set.insert(2 * prev + 2);
            dfs(root->right, 2 * prev + 2);
        }
    }
    FindElements(TreeNode* root) {
        u_set.insert(0);
        dfs(root, 0);
    }
    
    bool find(int target) {
        return (u_set.count(target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */