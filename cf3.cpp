#include<iostream>
using namespace std;

int main()
{
	long long int l,r,n,m,Crmin=1000000000,Prmin=1000000000,Clmax=0,Plmax=0;
  	cin>>n;
    while(n--)
    {
      cin>>l>>r;
      if(r<Crmin) Crmin=r;
      if(l>Clmax)
        Clmax=l;
    }
    cin>>m;
    while(m--)
    {
      cin>>l>>r;
      if(r<Prmin) Prmin=r;
      if(l>Plmax)
        Plmax=l;
    }
    if(Plmax-Crmin>0)
    cout<<Plmax-Crmin;
  else { if(Clmax-Prmin>0)
    cout<<Clmax-Prmin;
         else cout<<"0";
       }
	/* code */
	return 0;
}