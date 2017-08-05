#include<iostream>
#include<vector>
using namespace std;


int maxcost(int k,vector<int> &A)
{
   if(k==0) return 0;
   int cost;
   int costs[k+1];
   costs[0]=0;
   for(int i=1;i<=k;i++)
   {cost=INT_MIN;
   	for(int j=0;j<i;j++)
   { 	cost=max(cost,A[j]+costs[i-j-1]);
    }
    costs[i]=cost;
   }
   return costs[k];

}
int main()
{   int max=0;
	int t,n,k;
	vector<int> A;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&k);        //k->length of rod
		A.resize(k);
		for(int i=0;i<k;i++)    //A[]->cost array 
			cin>>A[i];          //A[i]-> cost for cutting into a piece of size i
	      
	      cout<<maxcost(k,A);
	}
	
	/* code */
	return 0;
}