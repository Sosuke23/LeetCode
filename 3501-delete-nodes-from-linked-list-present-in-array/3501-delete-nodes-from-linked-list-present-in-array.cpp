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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::unordered_set<int> st;
        for (auto x : nums) {
            st.insert(x);
        }

        ListNode *dummy = new ListNode();
        ListNode *now = dummy;
        while (head != NULL) {
            if (st.count(head->val)) {
                head = head->next;
                continue;
            }
            now->next = new ListNode(head->val);
            now = now->next;
            head = head->next;
        }
        return dummy->next;
    }
};