/*
LOGIC:
Just create a 3rd link list by adding each node of the 2 LL from strating to end ,
BUT insert the sum values into the third array from the head (front side) of the list.
Then traverse the 3rd list and wherever the value is >=10, then mod the value and 
add 1 as carry to the next element.
*/


#include<iostream>
using namespace std;

struct node
{
   int data;
   struct node* link;
};

struct node* noder(struct node* head,int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->link=NULL;
    newnode->data=data;

    if(head==NULL)
       head=newnode;

    else
    {
        struct node *ptr=root;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=newnode;
    }

    return newnode;


int main()
{
    
}