/* 

link: http://practice.geeksforgeeks.org/problems/delete-a-node-from-bst/1
explaination: http://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */
Node* inorSuc(Node* root)
{
    if(root==NULL)
      return NULL;
    if(root->left!=NULL)
      return inorSuc(root->left);  
    return root;
}

Node * deleteNode(Node *root,  int x)
{
    if(root==NULL)
    return NULL;
  
    if(x<root->data) 
       root->left=deleteNode(root->left,x);
   
    if(x>root->data)     
       root->right=deleteNode(root->right,x);
       
    if(root->data==x)
     {
         
         if(root->right==NULL)
            {
                Node* temp=root->left;
                free(root);     //deleting root
                return temp;
            }
         
         if(root->left==NULL)
           {   Node* temp=root->right;
               free(root);
               return temp;
           }
         Node* temp=inorSuc(root->right);  //control comes here when the node to be deleted has two children
         root->data=temp->data;
         root->right=deleteNode(root->right,temp->data);
         
     }
     
     return root;
        
  // your code goes here   
}