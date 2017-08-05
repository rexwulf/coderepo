#include<iostream>
using namespace std;
int A[100001];

int check(int a,int i,int j)
{
   for(int k=i;k<=j;k++)
   	if(a==A[k])
   		return 1;

   	return 0;
}
int main()
{
	int n,ok;
	cin>>n;
	int ans[n+1],ans2[n+1];
	for(int i=0;i<n;i++)
		ans[i]=0;
	for(int i=0;i<n;i++)
		ans2[i]=0;
	for(int i=0;i<n;i++)
		cin>>A[i];

for(int k=1;k<=n;k++)
	for(int i=0;i<n;i++)
	 {  ok=0;
	 for(int j=i;j<n&&ok<k;j++)
	  {
      if(!check(A[i],i,j))
      	{ok++;
      		i=j;
      	}
      }
	ans[k]++;
}
	for(int k=1;k<=n;k++)
	for(int i=n-1;i>=0;i--)
	 {  ok=0;
	 for(int j=i;j>=0&&ok<k;j--)
	  {
      if(!check(A[i],i,j))
      	{ok++;
      		i=j;
      	}
      }
	ans2[k]++;
}
for(int i=0;i<n;i++)
{
	if(ans[i]>ans2[i])
		cout<<ans2[i]<<" ";
	else cout<<ans[i]<<" ";
}
	return 0;
}
