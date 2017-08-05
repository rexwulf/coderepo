#include<iostream>
using namespace std;

int main()
{
    float a,sum;
    int i;
    cin>>a;
    while(a!=0.00)
    { sum=0;
        for(i=2;sum<a;i++)
          sum+=1/(float)(i);
           
       cout<<"\n"<<i-2<<" card(s)";
      cin>>a;
    }
    return 0;
}