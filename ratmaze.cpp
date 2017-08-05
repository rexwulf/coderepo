#include<iostream>
using namespace std;

int n;
int sol[100][100];
int solve(int A[100][100],int i,int j)
{
	if(!A[i][j])
		return 0;
	cout<<"\n"<<i<<" "<<j;
	if(i>n-1||j>n-1)
		return 0;
	if(i==n-1&&j==n-1)
		{
			sol[i][j]=1;
			return 1;
		}
    
    sol[i][j]=1;
    if( solve(A,i+1,j) || solve(A,i,j+1) )
    	return 1;
    else
    {
    	sol[i][j]=0;
    	return 0;
    }

}
int main()
{
	cin>>n;
	int A[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	if(solve(A,0,0))
		{
		    for(int i=0;i<n;i++)
		     {    cout<<"\n";
		     	  for(int j=0;j<n;j++)
		     		  cout<<sol[i][j]<<" ";
		     }
		 }	
	else
	{
		cout<<"No solution";
	}		
	return 0;
}