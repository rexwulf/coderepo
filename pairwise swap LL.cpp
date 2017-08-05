#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* newNoder(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void insert(struct node* head,int data)
{
   struct node *ptr=head;
   while(ptr->next)
     ptr=ptr->next;
   ptr->next=newNoder(data);
} 

struct node* func(struct node* head)
{
   if(head==NULL || head->next==NULL)
   	return head;
   
   struct node *temp=head->next;
   head->next=head->next->next;
   temp->next=head;
   
   head->next=func(head->next);
   return temp;
}

int main()
{
    struct node* head1=newNoder(5);
    insert(head1,1);
    insert(head1,3);
    insert(head1,2);
    insert(head1,7);
    
    head1=func(head1);

    while(head1)
    {
    	cout<<head1->data<<" ";
    	head1=head1->next;
    }
    return 0;
} 