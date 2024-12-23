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
int get(vector<int>& a) {
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    unordered_map<int, int> f;
    for (int i = 0; i < a.size(); i++) {
        f[a[i]] = i;
    }
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            continue;
        }
        res++;
        int p1 = f[b[i]];
        int old = a[i];
        a[i] = a[p1];
        a[p1] = old;
        f[a[i]] = i;
        f[old] = p1;
    }
    return res;
}
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        q.push(root);
        while (q.size()) {
            vector<int> level;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* top = q.front();
                q.pop();
                level.push_back(top->val);
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
            res += get(level);
        }
        return res;
    }
};
