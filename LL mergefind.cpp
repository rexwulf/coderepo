#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* link;
};

struct node* newNoder(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

void insert(struct node* head,int data)
{
   struct node *ptr=head;
   while(ptr->link)
     ptr=ptr->link;
   ptr->link=newNoder(data);
} 

struct node* findMerge(struct node* head1,struct node* head2)
{
    if(!head1 || !head2)
        return NULL;

    struct node *ptr1=head1, *ptr2=head2;
    int flag1=0,flag2=0;
    
    while(ptr1 && ptr2)
    {  
       if(ptr1->data == ptr2->data)
        return ptr1;

       ptr1=ptr1->link;
       ptr2=ptr2->link;

       if(!flag1 && ptr1==NULL)
        ptr1=head2, flag1=1;
       if(!flag2 && ptr2==NULL)
        ptr2=head1, flag2=1;
    }
   return NULL;
}
int main()
{
    struct node* head1=newNoder(5);
    insert(head1,1);
    insert(head1,3);
    insert(head1,2);
    insert(head1,7);
    struct node* head2=newNoder(6);
    insert(head2,2);
    insert(head2,7);
    cout<<"LL1:";
    while(head1)
    {
        cout<<" "<<head1->data;
        head1=head1->link;
    }

    cout<<"\n LL2: ";
    while(head2)
    {
        cout<<" "<<head2->data;
        head2=head2->link;
    }
    cout<<" Merged at: "<<findMerge(head1,head2)->data;
    return 0;
} 