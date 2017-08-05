#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct node
{
  int data;
  struct node *left,*right;
};

struct node* newNode(int data)
{
   struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}


void printer(stack<struct node*>& s)
{
   while(!s.empty())
    {
      cout<<" "<<s.top()->data;
      s.pop();
    }
}

void printStack(stack<struct node*> s)
{
  stack<struct node*> a(s);
  while(!a.empty())
  {
    cout<<" "<<a.top()->data;
    a.pop();
  }
  cout<<" ]";
}
void anc(struct node* root,stack<struct node*> s,int key)
{  
  while(1)
  {
    while(root && root->data!=key)     //root is not NULL and key not found
    {
      s.push(root);
      root=root->left;
    }
    
    if(root && root->data==key)        //key found
      {
        printer(s);
        return ;
      }
   
   while(s.top()->right==NULL)         //checking right of top stack node
   {
     root=s.top(),                     //taking the top node as root ans then removing it
          s.pop();
     
     while( !s.empty() && s.top()->right==root)  // checking for infinite loop between root->right->right and root
     {
       root=s.top(),
            s.pop();
     }     
   }
   
   root=(s.empty()? NULL : s.top()->right); 
  }
  
}

int main()
{
  struct node* root=newNode(1);
  root->right=newNode(3);
  root->right->right=newNode(2);
  root->right->right->right=newNode(9);
  root->right->left=newNode(5);
  root->right->left->left=newNode(6);
  root->right->left->right=newNode(4);
  root->right->left->right->right=newNode(7);
  root->right->left->right->right->left=newNode(8);
  stack<struct node*> s;
  anc(root,s,8);
   return 0;
}
