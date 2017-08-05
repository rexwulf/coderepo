#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int n1,n2,n3=0;
	string s1,s2,s3,temp;
	char c1[10],c2[10],c3[10];
	cin>>s1>>s2;
    n1=s1.length();
    n2=s2.length();
    c1[0]='x',c2[0]='y';
    strcpy(c1+1,s1.c_str());
    strcpy(c2+1,s2.c_str());
    
    int A[n1+1][n2+1];

    for(int i=1;i<=n1;i++)
    	A[i][0]=0;
    for(int j=1;j<=n2;j++)
    	A[0][j]=0;
    
    for(int i=1;i<=n1;i++)
       	for(int j=1;j<=n2;j++)
    	{   
    		if(c1[i]==c2[j]) A[i][j]=A[i-1][j-1]+1;
    		else A[i][j]=max(A[i-1][j],A[i][j-1]);
    	}

    	for(int i=0;i<=n1;i++)
    	{ cout<<endl;
       	for(int j=0;j<=n2;j++)
    	 cout<<A[i][j]<<" ";
        }
        int i=n1, j=n2; 
    	while(A[i][j])
    	{
    		if(A[i][j]==max(A[i][j-1],A[i-1][j]))
    	     {
    	     	if(A[i][j-1]>A[i-1][j])
    	     		j--;
    	     	else i--;
    	     }
    	     else
    	     	{
    	         c3[n3]=c1[i];
    	         n3++;
    	         i--,j--;
    	     }
    	}
         cout<<"\n"<<n3;
    	s3=c3;
        reverse(s3.begin(),s3.end());
    	cout<<s3;
	/* code */
	return 0;
}