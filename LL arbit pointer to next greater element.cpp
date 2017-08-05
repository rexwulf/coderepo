#include<iostream>
using namespace std;

  struct ListNode 
  {
      int val;
      ListNode *next , *nextG;
      ListNode(int x) : val(x), next(NULL) {}
  };

    void printG(ListNode* head)
    {
        ListNode *p=head;
        while(p)
        {
            cout<<"\n"<<p->val<<" -> ";
            (p->nextG) ? cout<<p->nextG->val : cout<<"NULL";
            p=p->nextG;
        }
    }
    ListNode* merge(ListNode* L1, ListNode *L2)
    {
        if(!L1)
            return L2;
        
        if(!L2)
            return L1;
        
        if(L1->val < L2->val)
        {
            L1->nextG= merge( L1->nextG , L2);
            return L1;
        }
        
        else
        {
            L2->nextG= merge( L1 , L2->nextG);
            return L2;
        }
        
       
    }
    
    void split(ListNode *head, ListNode **a, ListNode **b)
    {
        ListNode *slow=head ,*fast=head,*save=head;
        
        while(fast && fast->nextG)
            fast=fast->nextG->nextG,
            save=slow,
            slow=slow->nextG;
        
        save->nextG=NULL;
        *a=head;
        *b=slow;
        
    }
    
    ListNode *mergeSort(ListNode *head)
    {  
        if(head==NULL || head->nextG==NULL)
            return head;
        ListNode *a=NULL,*b=NULL;
        split(head,&a,&b);
        
        
        
        a=mergeSort(a);
        b=mergeSort(b);
        
        return merge(a,b);
        
    }
    
    ListNode *sortList(ListNode *head) {
        if(!head || head->nextG==NULL)
            return head;
        
        head=mergeSort(head);
        return head;
        }
    
int main()
{
    int n,a;
    cin>>n>>a;
    n--;
	ListNode* head=new ListNode(a) ,*p=head;
	while(n--)
    {
        cin>>a;
        p->next= new ListNode(a);
        p->nextG=p->next;
        p=p->next;
    }
	
	head=mergeSort(head);
	
	printG(head);

	return 0;
}