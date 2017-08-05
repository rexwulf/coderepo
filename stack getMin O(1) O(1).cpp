/*
file:///Users/rex/Downloads/us.sitesucker.mac.sitesucker/www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/index.html

I/P: 3 5 2 1 1 -1


*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int A[n],   minEle = INT_MAX;
  stack<int> s;
  for(int i=0;i<n;i++)
    {
      cin>>A[i];
      if(A[i]<minEle)
      {
        s.push(2*A[i] - minEle);
        minEle=A[i];
      }

      else
      {
        s.push(A[i]);
      }
      cout<<"\n inserted: "<<A[i]<<"  min="<<minEle;
    }


    for(int i=0;i<n;i++)
    {
      if(s.top()<minEle)
      {
        cout<<"\n deleted: "<<minEle;   //in this case the top element is the min element

        minEle = 2*minEle - s.top();
        cout<<" min="<<minEle<<" ";
        s.pop();
      }

      else
      { 
        cout<<"\n deleted: "<<s.top()<<" min="<<minEle<<" ";
        s.pop();
      }
    }

   return 0;
}
