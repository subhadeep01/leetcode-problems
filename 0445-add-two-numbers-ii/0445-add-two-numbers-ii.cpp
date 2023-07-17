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
    ListNode* reverseList(ListNode* head) {
       if(head==NULL)return NULL;
       ListNode *prev=NULL;
       ListNode *curr=head;
       ListNode *nxt=head->next;
       while(curr!=NULL)
       {
           curr->next=prev;
           prev=curr;
           curr=nxt;
           if(nxt!=NULL)
           nxt=nxt->next;
       }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
         if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        ListNode* dummy =new ListNode(0);
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum=0;
            if(l1!=NULL)
            {
            sum+=(l1->val);
            l1=l1->next;
            }
            if(l2!=NULL)
            {sum+=(l2->val);
            l2=l2->next;
            }
            sum+=carry;
            ListNode *z=new ListNode(sum%10);
            carry=sum/10;
            temp->next=z;
            temp=temp->next;
        }
        return reverseList(dummy->next);
    }
};