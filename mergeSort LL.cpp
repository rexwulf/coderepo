#include<iostream>
using namespace std;

  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    void print(ListNode* head)
    {
        ListNode *p=head;
        while(p)
        {
            cout<<p->val<<" ";
            p=p->next;
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
            L1->next= merge( L1->next , L2);
            return L1;
        }
        
        else
        {
            L2->next= merge( L1 , L2->next);
            return L2;
        }
        
       
    }
    
    void split(ListNode *head, ListNode **a, ListNode **b)
    {
        ListNode *slow=head ,*fast=head,*save=head;
        
        while(fast && fast->next)
            fast=fast->next->next,
            save=slow,
            slow=slow->next;
        
        save->next=NULL;
        *a=head;
        *b=slow;
        
    }
    
    ListNode *mergeSort(ListNode *head)
    {  
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *a=NULL,*b=NULL;
        split(head,&a,&b);
        
        cout<<"\nSplitted into : ";
        print(a);
        cout<<" and ";
        
        print(b);
        a=mergeSort(a);
        b=mergeSort(b);
        cout<<"\nMerging: ";
        print(a);
        cout<<" and ";
        print(b);
        return merge(a,b);
        
    }
    
    ListNode *sortList(ListNode *head) {
        if(!head || head->next==NULL)
            return head;
        
        head=mergeSort(head);
        return head;
        }
    
int main()
{
	ListNode* head=new ListNode(2);
	head->next=new ListNode(1);
	head->next->next=new ListNode(3);
	cout<<"\n Original list : ";
	print(head);
	head=mergeSort(head);
	cout<<"\n Sorted list : ";
	print(head);
	return 0;
}