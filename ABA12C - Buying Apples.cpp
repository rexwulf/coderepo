#include<iostream>
#include<vector>
#define MAX 60000
using namespace std;


int mincost(int k,vector<int> &A)
{
   if(k==0) return 0;
   int cost;
   int costs[k+1];
   costs[0]=0;
   for(int i=1;i<=k;i++)
   {cost=MAX;
   	for(int j=0;j<i;j++)
   {  if(A[j]!=-1) cost=min(cost,A[j]+costs[i-j-1]);
    }
    costs[i]=cost;
   }
   return costs[k];

}
int main()
{   int max=0,ans;
	int t,n,k;
	vector<int> A;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&n,&k);        //k->length of rod
		A.resize(k);
		for(int i=0;i<k;i++)    //A[]->cost array 
			cin>>A[i];          //A[i]-> cost for cutting into a piece of size i
	      
	      ans=mincost(k,A);
	      if(ans==MAX) cout<<"-1";
	      else cout<<ans;
	      cout<<"\n";
	}
	
	/* code */
	return 0;
}