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
    void travo(vector<int> &vec,TreeNode* root)
    {
        if(root==NULL) return;
        
        travo(vec,root->left);
        vec.push_back(root->val);
        travo(vec,root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        travo(vec,root);
        sort(vec.begin(),vec.end());
        return vec[k-1];
    }
};

