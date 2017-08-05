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



int main()
{
    struct node* head1=newNoder(5);
    insert(head1,1);
    insert(head1,3);
    insert(head1,2);
    insert(head1,7);
    struct node *head2 = head1->next , *p1=head1, *p2=head2 , *temp=NULL;

    
    while((p1 && p1->next )|| ( p2  && p2->next))
    {
     
     if(p1)
     { 
        p1->next= p1->next->next;
        p1=p1->next;
     }

     if(p2)
      {
        p2->next= p2->next->next;
        p2=p2->next;
      }  
    }
    
    p1=head1,p2=head2;
    while( p1 || p2)
    {
      cout<<"\n";
     if(p1) 
      {
        cout<<p1->data;
        p1=p1->next;
      }
      else cout<<" ";
      
      if(p2)
        { cout<<"   "<<p2->data;
          p2=p2->next;
        }
    }
    return 0;
} 




