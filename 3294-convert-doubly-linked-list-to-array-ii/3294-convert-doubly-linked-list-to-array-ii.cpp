/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *node){
        Node *t = node;
        t = t->next;
        std::vector<int> res;
        while (node != nullptr) {
            res.push_back(node->val);
            node = node->prev;
        }
        reverse(begin(res), end(res));

        while (t != nullptr) {
            res.push_back(t->val);
            t = t->next;
        }
        
        return res;
    }
};