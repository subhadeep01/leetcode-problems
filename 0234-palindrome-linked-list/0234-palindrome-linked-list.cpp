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
    ListNode* reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;       
        }
        slow = reverse(slow->next);
        ListNode* dummy=head;
       // slow=slow->next;
        while(slow!=NULL)
        {
            if(dummy->val==slow->val)
            {
                dummy=dummy->next;
                slow=slow->next;
            }
            else
                return false;
        }
        return true;
    }
};