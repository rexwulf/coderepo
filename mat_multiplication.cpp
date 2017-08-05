#include<iostream>
using namespace std;
int dp[1000][1000];
void calc(int A[],int i,int j)
{
  if(i==j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  
  for(int L=2;L<j-1;L++)
  { for(int b=i;b<j-(L-1);b++)
     for(int c=;c<;c++)
  }
}
int main()
{
	int A={10,50,30,20,50};
	int n=sizeof(A)/sizeof(A[0]);
    calc(A,1,n-1);
    cout<<
	/* code */
	return 0;
}