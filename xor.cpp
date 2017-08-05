#include<iostream>
using namespace std;

int main()
{
	int a,b,ans;
	bool a1,b1,xorbit;
		scanf("%d %d",&a,&b);
		
		for(int i=31;i>=0;i--)
		{
               a1=a&(1<<i);
               b1=b&(1<<i);

               xorbit=(a1&b1)? 0 : (a1|b1);
               
               ans=ans<<1;
               ans=ans|xorbit;
		}
		cout<<ans;

	/* code */
	return 0;
}