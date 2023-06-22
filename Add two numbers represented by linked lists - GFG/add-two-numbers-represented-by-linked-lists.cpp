//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     struct Node* reverseList(struct Node* head) {
       if(head==NULL)return NULL;
       Node *prev=NULL;
       Node *curr=head;
       Node *nxt=head->next;
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
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        l1=reverseList(l1);
        l2=reverseList(l2);
     if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        Node* dummy =new Node(0);
        Node* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum=0;
            if(l1!=NULL)
            {
            sum+=(l1->data);
            l1=l1->next;
            }
            if(l2!=NULL)
            {sum+=(l2->data);
            l2=l2->next;
            }
            sum+=carry;
            Node *z=new Node(sum%10);
            carry=sum/10;
            temp->next=z;
            temp=temp->next;
        }
        return reverseList(dummy->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends