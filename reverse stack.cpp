#include<iostream>
#include<stack>
using namespace std;


/*
2                                   1
3     3                        1    6
6     6    6              1    6    3
1     1    1    1     1   6    3    2                              
*/



void printStack(stack<int> a)
{
  stack<int> b;
  int temp;
  while(!a.empty())
  {
     temp=a.top(), a.pop();
     cout<<" "<<temp;
     b.push(temp);
  }

  while(!b.empty())
  {
    a.push(b.top()), b.pop();
  }
}

void insertAtBottom(stack<int>& a,int data)
{
   //cout<<"\n temp:"<<data<<" a: "; printStack(a);
   if(a.empty())
     a.push(data);

   else{
     int temp=a.top();
              a.pop();
     insertAtBottom(a,data);
     a.push(temp);         
   }
}

void revStack(stack<int>& a)
{
  if(a.empty())
    return;

  else
  {
    int temp=a.top();
             a.pop();
    revStack(a);  //calling itself till it finds the bottom element

    insertAtBottom(a,temp);     //now start putting elements from "bottom to top" at the bottom
  }
}






int main()
{
   stack<int> a,b;
   int A[]={2,8,4,1,9};
   int n=5;
   for(int i=0;i<n;i++)
    a.push(A[i]);

    printStack(a);     cout<<"\n";
   
    revStack(a);
   
    printStack(a);
   return 0;
}