/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> add;
        for (; head != nullptr; head = head -> next) {
            add.push_back(head -> val);
        }
        vector<int> res;
        res.push_back(add.front());
        for (int i = 1; i < (int)add.size(); i++) {
            int Gcd = __gcd(add[i - 1], add[i]);
            res.push_back(Gcd);
            res.push_back(add[i]);
        }
        ListNode *dummy = new ListNode();
        ListNode *now = dummy;
        for (auto x : res) {
            now -> next = new ListNode(x);
            now = now -> next;
        }
        return dummy -> next;
    }
};