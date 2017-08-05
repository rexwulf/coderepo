#include<iostream>
#include<map>
#include<string.h>
#include<vector>
#define height 4
using namespace std;
int width;
vector<int> top;
map<int,int> m;
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
  yo->left=NULL;
  yo->right=NULL;
  return yo;
}


int getHeight(struct node* root)
{
  if(root==NULL) return 0;
  return max(getHeight(root->left), getHeight(root->right)) +1;
}
int getWidth(struct node* root,int level)
{
  if(root==NULL) return 0;
  if(level==1) return 1;
  else return getWidth(root->left,level-1)+getWidth(root->right,level-1);
}


int maxWidth(struct node* root)
{
  int h=getHeight(root) ,maxw=-1;
  for(int i=0;i<h;i++)
   maxw=max(maxw,getWidth(root,i));
   return maxw;

}


void printInorder(struct node* root )
{ 
  if(root==NULL)
    return;
  printInorder(root->left);
  cout<<"\t"<<root->data;
  printInorder(root->right);
}
void topview(struct node* root, int level,int horiz)
{  
    if(root==NULL) return;
     cout<<"\nroot:"<<root->data<<" level="<<level<<" horiz="<<horiz;
    if(level==0)
       {if(!m[horiz+width]) 
                  top[horiz+width]=root->data,m[horiz+width]=1;
         else return;
        } 
else{

      topview(root->left,level-1,horiz-1);
      topview(root->right,level-1,horiz+1);
    }
}

int main()
{

   struct node* root=newNode(1);
   root->left=newNode(2);
    root->right=newNode(3);
    root->left->right=newNode(4);
    root->left->right->right=newNode(5);
    root->left->right->right->right=newNode(6);
   printInorder(root);
   width=maxWidth(root);
   cout<<"\n..........................................\n";
   top.resize(2*width+1);
   for(int i=0;i<2*width;i++)
      top[i]=0,m[i]=0;

   int h=getHeight(root); 
  for(int i=0;i<h;i++) 
   topview(root,i,0);
 cout<<"\nTOP VIEW: ";
   for(int i=0;i<2*width+1;i++)
    if(top[i])cout<<"\t"<<top[i];
}