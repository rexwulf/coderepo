#include<iostream>
using namespace std;

int main()
{
	int u,g,k,ans=1,temp;
	scanf("%d %d",&u,&g);
	int safe[g];
	for(int i=0;i<g;i++)
		safe[i]=0;
	temp=g;
	while(temp--)
	{   
		scanf("%d",&k);
		int A[k];
		for(int i=0;i<k;i++)
			cin>>A[i];
		for(int i=0;i<k;i++)
			for(int j=i;j<k;j++)
			 if(A[i]==(-A[j]))
				  safe[g-temp-1]=1;

	}

	for(int i=0;i<g;i++)
		if(safe[i]==0)
			ans=0;
	if(ans) cout<<"NO";
     else   cout<<"YES";
	/* code */
	return 0;
}