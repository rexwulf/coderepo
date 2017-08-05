#include<iostream>
#include<queue>
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data)
{
  struct node* yo=(struct node*)malloc(sizeof(struct node));
  yo->data=data;
  yo->left=NULL,yo->right=NULL;
  return yo;
}
void printInorder(struct node* root )
{
  if(root==NULL)
    return;
  printInorder(root->left);
  cout<<"\t"<<root->data;
  printInorder(root->right);
}
int searchIt(int A[],int s,int e,int key)
{ 
  
  for(int i=s;i<=e;i++)
    if(A[i]==key)
      return i;
}
struct node* func(int I[],int P[],int start,int end)
{ static int pindex=0;
  if(start>end)
    return NULL;

  struct node* tNode=newNode(P[pindex++]);

  if(start==end)
    return tNode;
 int iindex=searchIt(I,start,end,tNode->data);

  tNode->left=func(I,P,start,iindex-1);
  tNode->right=func(I,P,iindex+1,end);

  return tNode;
}

int main()
{
   int n;
   cin>>n;
   int I[n],P[n];
   for(int i=0;i<n;i++)
    cin>>I[i];
   for(int i=0;i<n;i++)
     cin>>P[i];

   struct node* root=func(I,P,0,n-1);
   printInorder(root);
}