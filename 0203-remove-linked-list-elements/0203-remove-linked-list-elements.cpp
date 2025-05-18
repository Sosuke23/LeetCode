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
  ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    
    while(dummy!=NULL && dummy->next!=NULL)
    {
        if(dummy->next->val == val)
        {
            ListNode* temp = dummy->next;
            dummy->next=dummy->next->next;
            delete(temp);
        }
        else{
            dummy=dummy->next;
        }
    }
    return pre->next;
}

};