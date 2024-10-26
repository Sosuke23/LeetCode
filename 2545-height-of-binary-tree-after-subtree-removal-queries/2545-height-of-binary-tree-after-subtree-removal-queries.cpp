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
const int N = 1e5 + 5;

int ans[N], mxdep[N];

int dfs1(TreeNode *u) {
    if (!u) return 0;
    int mx = max(dfs1(u -> left), dfs1(u -> right));
    mxdep[u -> val] = mx + 1; return mx + 1;
}

void dfs2(TreeNode *u, int ndep, int now) {
    if (!u) return;
    ans[u -> val] = now;
    now = max(now, ndep - 1);
    dfs2(u -> left, ndep + 1, max(now, (u -> right ? mxdep[u -> right -> val] : -100000) + ndep - 1));
    dfs2(u -> right, ndep + 1, max(now, (u -> left ? mxdep[u -> left -> val] : -100000) + ndep - 1));
}

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& a) {
        dfs1(root); dfs2(root, 1, 0);
        vector <int> res(a.size());
        for (int i = 0; i < a.size(); i++) res[i] = ans[a[i]];
        return res;
    }
};