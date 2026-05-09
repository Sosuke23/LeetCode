/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int max_val = 0;

    int dfs(Node* root) {
        if (!root) {
            return 0;
        }

        int first_max = 0, second_max = 0, temp = 0;

        for (Node* neighbor : root->children) {
            int val = 1 + dfs(neighbor);

            if (first_max < val) {
                temp = first_max;
                first_max = val;
                second_max = temp;
            } else if (second_max < val) {
                second_max = val;
            }
        }

        max_val = max(max_val, first_max + second_max);

        return first_max;
    }

    int diameter(Node* root) {
        dfs(root);
        return max_val;
    }
};