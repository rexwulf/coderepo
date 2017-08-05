#include<iostream>
#define max 100
using namespace std;

class stack{

public:
  int top;
  int size;
  int A[max];

  stack(int a){ top=-1; size=a;}
  void push(int);
  void pop();
  void print();
  int Top();
  bool isEmpty();
  bool isFull();
};


void
stack::push(int a)
{
  if(top+1>size)
    cout<<"Overflow";

  else
    A[++top] = a;
}


void
stack::pop()
{
  if(top==-1)
    cout<<"Underflow";

  else
    A[top--]=0;
    
}

void
stack::print()
{
  int n=top;
  for(int i=0;i<=n;i++)
   cout<<"  "<<A[i];
}

int
stack::Top()
{
  return Top();
}

bool
stack::isEmpty()
{
  if(top==-1)
    return true;
  return false;
}

bool
stack::isFull()
{
  if(top==size)
    return true;
  return false;
}





int main()
{
   stack a(5);
   int A[]={2,8,4,1,9};
   int n=5;

   for(int i=0;i<n;i++)
    a.push(A[i]);

    a.print();   
   
    a.pop();
    cout<<"\n after popping : ";
   a.print();
   
    cout<<"\n after pushing 5: ";
    a.push(5);
    a.print();
   return 0;
}