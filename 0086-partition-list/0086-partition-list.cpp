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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        ListNode node1(0);
        ListNode node2(0);
        ListNode *p1=&node1, *p2=&node2;
        while(head)
        {
            if(head->val<x)
            {
                p1->next=head;
                p1=head;
            }
            else
            {
                p2->next=head;
                p2=head;
            }
            head=head->next;
        }
        p2->next=NULL;
        p1->next=node2.next;
        return node1.next;
    }
};