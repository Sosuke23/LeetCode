/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right)
 * {}
 * };
 */
class Solution {

public:
    bool checkEquivalence(Node* root1, Node* root2) {
        vector<int> c1(26, 0), c2(26, 0);
        dfs(c1, root1);
        dfs(c2, root2);

        for (int i = 0; i < 25; i++) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<int>& m, Node* root) {
        if (root == nullptr) {
            return;
        }

        if (root->val != '+') {
            m[root->val - 'a']++;
        }

        dfs(m, root->left);
        dfs(m, root->right);
    }
};