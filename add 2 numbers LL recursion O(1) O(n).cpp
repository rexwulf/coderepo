/*

*/


#include<iostream>
#include<math.h>
using namespace std;
int carry ,ten=1;
struct node
{
   int data;
   struct node* next;
};

struct node* noder(int data)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;

}

int len(node *head)
{
    node* p=head;
    int count=0;
    while(p)
      count++ ,p=p->next;

      return count; 
} 

int func(node* l1,node* l2)
{
    if(!l1 && !l2)
      return 0;
    
    int sum;
    if(l1 && l2)
      sum=func(l1->next,l2->next);
    else
      sum= l1 ? func(l1->next,NULL) : func(NULL , l2->next);

    int ans = (l1 ? l1->data : 0) + (l2 ? l2->data : 0) + carry;
    carry= (ans-ans%10)/10;
    ans%=10;
    ten*=10;
    cout<<l1->data<<"+"<<l2->data<<"="<<ans<<" carry="<<carry<<" sum="<<sum<<" returning:"<<sum+(ten/10)*ans<<endl;
    return sum + (ten/10)*ans ;    
}

int main()
{
    node *l1=noder(2);
    l1->next=noder(3);
    l1->next->next=noder(4);
    l1->next->next->next=noder(5);
    node *l2=noder(1);
    l2->next=noder(1);
    l2->next->next=noder(1);
    
   

   return 0;
}