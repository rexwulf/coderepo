#include<iostream>
#include<map>
#include<math.h>
#define ll long long
using namespace std;

map< ll , ll > A;


ll calc(ll n)
{   
	if(!n)
		return 0;

	if(!A[n])
		A[n]=max(n , calc(floor(n/2)) + calc(floor(n/3)) + calc(floor(n/4)) );

	return A[n];
   
}
int main()
{   
	ll n;
	
	while(scanf("%ld",&n)>0)
	{ 
		cout<<calc(n)<<"\n";
		
	}
	/* code */
	return 0;
}