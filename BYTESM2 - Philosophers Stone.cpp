#include<iostream>
using namespace std;

int h,w;

int maxo(int a,int b,int c)
{
	return max(a,max(b,c));
}

int main()
{
	int t,ans;
	scanf("%d",&t);
	while(t--)
	{   ans=-1;
        scanf("%d %d",&h,&w);
        int A[h][w];
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>A[i][j];


	 for(int i=1;i<h;i++)	
	   for(int j=0;j<w;j++)
         { 
         	if(j>0 && j<w-1)
			 A[i][j]=A[i][j]+maxo( A[i-1][j-1] , A[i-1][j] ,A[i-1][j+1] );
              
			else
			{  
				if(j>0)
			     A[i][j]=A[i][j]+max( A[i-1][j-1] , A[i-1][j]);
               
			    else   
			     A[i][j]=A[i][j]+max( A[i-1][j] , A[i-1][j+1]);
			    	
			}
       		ans=max(ans,A[i][j]);
         }
        cout<<ans<<"\n";	
	}
	/* code */
	return 0;
}