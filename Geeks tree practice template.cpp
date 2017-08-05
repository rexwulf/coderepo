#include<iostream>
#include<map>
using namespace std;
 struct Node {
      int data;
      Node *left;
      Node *right;
  };

Node* noder(int data)
{
  Node* newNode=new Node;
  newNode->data=data;
  newNode->left=newNode->right=NULL;
  return newNode;
}

void inorder(Node* root)
{
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void insert(Node **root,int par,int child,char which)
{
    if(*root==NULL)
      return;
 cout<<"\ninserting:"<<(*root)->data;
    if( (*root)->data == par)
    {
       Node* temp=noder(child);
       if(child=='L')
         (*root)->left=temp;
       
       else
         (*root)->right=temp;
    }

    else
    {
      insert( &( (*root)->left)  ,par,child,which);
      insert( &( (*root)->right) ,par,child,which);
    }
}



void func(Node *root,Node **head,Node **p)
{  cout<<" \n"<<root->data;
    if(root==NULL)
     return ;
     
     if(!root->left && !root->right)
     {
         if(*head)
         {
            root->left = *p; //prev
            (*p)->right = root; //next
            *p=root;
         }
         else
           *head=*p=root;
     }
    func(root->left,head,p);
    func(root->right,head,p);
}
Node *convertToDLL(Node *root,Node **head_ref)
{   Node *p=NULL;
    func(root,head_ref,&p);
    return *head_ref;
//add code here.
}

int main()
{
   int t,n;
   int a,b;
   char child;
   while(t--)
   {
    cin>>n;
    Node* root=NULL;
    int flag=0;
    while(n--)
    {
       
       cin>>a>>b>>child;
       if(flag) insert(&root,a,b,child);
       else
       {
        root=noder(a);
        if(child=='L')
          root->left=noder(b), root->right=NULL;
        else
          root->right=noder(b),root->left=NULL;
       }
    }
   
   inorder(root);


    Node *head;
    convertToDLL(root,&head);
    while(head)
    {
      cout<<head->data<<" ";
      head=head->right;
    }




   cout<<"\n";
   }
   
   return 0;
}