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
    vector<long long> zigzagLevelSum(TreeNode* root) {
        deque<TreeNode*>q;
        vector<long long>ans;
        bool isOdd = true;
        // true : left to right, stop if no left child
        // false: right to left, stop is no right child
        q.push_back(root);
        while(!q.empty()){
            int sz = q.size();
            long long sum = 0;
            bool isStop = false;
            while(sz){
                TreeNode* n = isOdd? q.front() : q.back();             
                if(isOdd){
                    q.pop_front();
                    if(n->left) q.push_back(n->left);   
                    else isStop = true;                                       
                    if(n->right) q.push_back(n->right);                    
                } else {
                    q.pop_back();
                    if(n->right) q.push_front(n->right);
                    else isStop = true;                    
                    if(n->left) q.push_front(n->left);                    
                }
                if(!isStop) {
                    sum += n->val;
                }
                sz--;
            }
            ans.push_back(sum);
            isOdd ^= true;
        }
        return ans;
    }
};