#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	string str;
	int n,len;
	cin>>str;
	while(str!="bye")
	{   n=str.length();
		int A[n],sum[n],dp[26][26]={0};
		A[0]=str[0]-'0';
		sum[0]=0;
		for(int i=1;i<n;i++)
         {A[i]=str[i]-'0';
          sum[i]=sum[i-1]+A[i];
          }
     int prevsum=0;
     for(int i=2;i<n;i++)
     	for(int j=1;j<=i;j++)    //length of grp->i-j
     	{ len=i-j;
           if(sum[len]>prevsum){
           	dp[i][j]++;
           	prevsum=sum[len];
           }
        }
		cin>>str;
	}
	/* code */
	return 0;
}