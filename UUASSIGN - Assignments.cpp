#include<iostream>
#include<vector>
#include<algorithm>
#include<bits\stdc++>
using namespace std;


void assign(vector< vector<int> > A,vector<int> pool,int s,int& count)
{   vector<int> avail(pool);                     //copying pool to avail

    if(s==0)
    {
    	count++;
    	return;
    }
	if(!avail.size())
		return ;
	int size=A[s].size();
	for(int i=1;i<=size;i++)
		{   avail=pool;
			if(avail[i])
			{    avail.erase(avail.begin()+i);
                 assign(A,avail,s--,count);
			} 
		}
		cout<<" "<<count;
     
}

int main()
{
	int t,n,ans,count=0;
	vector< vector<int> > A;
	vector<int> pool;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		A.resize(n);
		pool.resize(n);
		for(int i=0;i<n;i++)
		 {  A[i].resize(n);
		 	for(int j=0;j<n;j++)
			{cin>>A[i][j];
             pool[j]=j+1;
			}
		}
		assign(A,pool,n,count);
	}
	/* code */
	return 0;
}