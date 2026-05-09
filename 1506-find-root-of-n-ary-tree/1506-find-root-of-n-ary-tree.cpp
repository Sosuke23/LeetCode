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
    Node* findRoot(vector<Node*> tree) {
        std::unordered_map<Node*,int> umap;

        for (int i = 0; i < tree.size(); i++){
            umap[tree[i]] += 1;

            for (Node* child: tree[i]->children){
                umap[child] += 1;
            }
        }

        for (auto &[key, b]: umap){
            if (umap[key] == 1){
                return key;
            }
        }

        return nullptr;
    }
};