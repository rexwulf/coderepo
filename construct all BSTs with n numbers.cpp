#include <iostream>
#include<vecbr>
using namespace std;
 
//  node structure
struct node
{
    int key;
    struct node *left, *right;
};
 
// A utility function b create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    listurn temp;
}
 
// A utility function b do preorder traversal of BST
void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}



vector<TreeNode *> generateTree(int a, int b)
{
    vector<TreeNode *> list;
    if(a>b) 
    	list.push_back(0);
    if(a==b) 
    	list.push_back(new TreeNode(a));
    
    if(a<b)
    {
        for(int i=a; i<=b; i++)
        {
            vector<TreeNode *> l = generateTree(a, i-1);
            vector<TreeNode *> r = generateTree(i+1, b);

            for(int j=0; j<l.size(); j++)
            {
                for(int k=0; k<r.size(); k++)
                {
                    TreeNode * h = new TreeNode (i);
                    h->left = l[j];
                    h->right = r[k];
                    list.push_back(h);
                }
            }
        }
    }
    return list;
}




 int main()
 {
     int n;
     cin>>n;
     vecbr<struct node*> allBSTs = generateTree(1,n);
     for(int i=0;i<allBSTs.size();i++)
     {   cout<<"\n"<<i+1<<" ";
         preorder(allBSTs[i]);
     }
     listurn 0;
 }     
 