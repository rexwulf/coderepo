#include<iostream>
#include<stack>
using namespace std;


void stackInsert(stack<int>& s,int val)
{

   if(s.empty() || val>s.top())
     s.push(val);

   else
   {
      int temp=s.top();
               s.pop();      //remove the bigger element
      stackInsert(s,val);    //search and place the element in the sorted list without the bigger element just found
      s.push(temp);          //place the bigger element back
   }
}

void stackSort(stack<int>& a,stack<int>& s)
{
  if(a.empty())
    return;

  int temp=a.top();
           a.pop();
  stackInsert(s,temp);
  stackSort(a,s);
}

void printStack(stack<int> a)
{
  stack<int> b;
  int temp;
  cout<<"\n";
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

int main()
{
   stack<int> s,a;
   int A[]={2,8,4,1,9};
   int n=5;
   for(int i=0;i<n;i++)
    a.push(A[i]);

   stackSort(a,s);

   while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
   return 0;
}