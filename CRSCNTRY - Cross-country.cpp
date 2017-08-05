#include<iostream>
using namespace std;
void displayme(int a[],int n)
{ cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<" "<<a[i];
}

int calc(int Agnes[],int Tom[],int a,int t)
{
	int A[a+1][t+1];
    int cmn_n=0;
	int common[10];
    
    for(int i=0;i<=a;i++)
    	A[i][0]=0;
    for(int j=0;j<=t;j++)
    	A[0][j]=0;
    
    for(int i=1;i<=a;i++)
       	for(int j=1;j<=t;j++)
    	{   
    		if(Agnes[i-1]==Tom[j-1]) A[i][j]=A[i-1][j-1]+1;
    		else A[i][j]=max(A[i-1][j],A[i][j-1]);
    	}

        return A[a][t];
}
int main()
{
	int testcase,checkpts,temp, Agnes[1001],Tom[1001];
	scanf("%d",&testcase);
	while(testcase--)
	{   int a=-1,t,checkpts=-1;
		while(1)
		{
			scanf("%d",&Agnes[++a]);
			if(!Agnes[a])
				break;
			
		}
		 
		 while(1)
		 {  t=-1;
		 	while(1)
		 	{ 
		 		scanf("%d",&Tom[++t]);
				if(!Tom[t])
					break;					
				
		 	}
		 	if(!Tom[0])
		 		break;
		 	
		 	checkpts=max(checkpts,calc(Agnes,Tom,a,t));
		 }

		cout<<checkpts<<"\n";
	}
	/* code */
	return 0;
}