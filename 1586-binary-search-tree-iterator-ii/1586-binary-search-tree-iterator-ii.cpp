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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        for (; root; root = root->left) {
            nexts.push({root, true});
        }
    }

    bool hasNext() { return !nexts.empty(); }

    int next() {
        auto [next, push] = nexts.top();
        nexts.pop();

        for (auto n = next->right; push && n; n = n->left)
            nexts.push({n, true});

        prevs.push(next);
        return next->val;
    }

    bool hasPrev() { return prevs.size() > 1; }

    int prev() {
        nexts.push({prevs.top(), false});
        prevs.pop();

        return prevs.top()->val;
    }

private:
    stack<TreeNode*> prevs;
    stack<pair<TreeNode*, bool>> nexts;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */