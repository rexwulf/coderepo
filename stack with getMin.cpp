#include<iostream>
#define max 100
using namespace std;

class stack{

public:
  int top;
  int size;
  int A[max];
  int B[max];

  stack(int a){ top=-1; size=a;}
  void push(int);
  void pop();
  void print();
  void printMin();
  int Top();
  int getMin();
  bool isEmpty();
  bool isFull();
};


void
stack::push(int a)
{
  if(top+1>size)
    cout<<"Overflow";

  else
    { B[top+1]=a;
      A[++top] = a;
         
         if(top)   //to avoid B checking for index=-1
         { if(B[top-1]>A[top])
             B[top]=A[top];
           else
             B[top]=B[top-1];
         }
 
     }
}


void
stack::pop()
{
  if(top==-1)
    cout<<"Underflow";
  
  else
  {
    B[top]=INT_MAX;  
    A[top--]=0;
  }  
}

void
stack::print()
{
  int n=top;
  for(int i=0;i<=n;i++)
   cout<<"  "<<A[i];
}

void
stack::printMin()
{
  int n=top;
  for(int i=0;i<=n;i++)
   cout<<"  "<<B[i];
}

int
stack::Top()
{
  return Top();
}

int
stack::getMin()
{
  return B[top];
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
   int A[]={6,8,4,9,1};
   int n=5;

   for(int i=0;i<n;i++)
    a.push(A[i]);

    a.print();  
    cout<<"\n Min: ";         
    a.printMin();
   
 
    cout<<"\n after popping : ";
    a.pop();
    a.print();

    cout<<"\n Min: ";    
    a.printMin();
   
    cout<<"\n after pushing 1: ";
    a.push(1);
    a.print();

    cout<<"\n Min: ";
    a.printMin();
   return 0;
}