#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
  string str;
  cin>>str;

  stack<char> s;
  int count=0;
  int n=str.length();

  if(n%2==1)
  { cout<<"CAN'T";
    return 0;
  }

    for(int i=0;i<n;i++)
     {
       if(str[i]=='{')
         s.push(str[i]);
       else
       {
        if(s.empty())
        {
          count++;
          s.push('{');
        }
        else
          s.pop();
       }
     }
   int count1=0;
     while(!s.empty())
     {
      s.pop();
      count1++;
     }

 cout<<count+count1/2;
   return 0;
}
