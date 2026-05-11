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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) return "";
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        ans.push_back(root->val);
        ans.push_back(-1);
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                Node* curr = q.front();
                q.pop();
                for (auto neigh: curr->children){
                    ans.push_back(neigh->val);
                    q.push(neigh);
                }
                ans.push_back(-1);
            }
        }
        string ser;
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] == -1){
                ser += "-1,";
            }else{
                ser += to_string(ans[i]) + ',';
            }
        }
        return ser;
        
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return nullptr;
        int j = 0;
        vector<int> level;

        for (int i = 0; i < data.length(); i++){
            if (data[i] == ','){
                int num = stoi(data.substr(j,i-j));
                level.push_back(num);
                j =  i+1;
            }
        }

        queue<Node*> q;
        Node* root = new Node(level[0]);
        int idx = 2;
        q.push(root);
        while (!q.empty() && idx < level.size()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                Node* par = q.front();
                q.pop();
                while (level[idx] != -1){
                    Node* node = new Node(level[idx]);
                    idx++;
                    par->children.push_back(node);
                    q.push(node);
                }
                idx++;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));