#include<iostream>
#define  max 100
using namespace std;

int main()
{   
	int t,N,M,flag;
	char A[max][max];
	cin>>t;
	while(t--)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>A[i][j];
        flag=1;
		for(int i=0;i<N && flag==1;i++)
			for(int j=0;j<M && flag==1;j++)
				{  if(A[i][j]=='W')
					{
						if(A[i][j-1]!='B')
						{ flag=0;
							break;
						}
						else{
									while(A[i][j+1]=='W')
									{
										j++;
									}
									if(A[i][j+1]!='B')
									{
										flag=0;
										break;
									}

						    }
                        
		     	    }
				}

      for(int j=0;j<M && flag==1;j++)
       for(int i=0;i<N && flag==1;i++)
       {   
       	if(i!=N-1)
           { if(A[i][j]=='B'&&A[i+1][j]!='B')
	           {
	           	flag=0;
	           	break;
	           }
             if(A[i][j]=='W')
             {
             	if(A[i+1][j]!='B')
             	{
             		if(A[i+1][j]=='W')
             			while(A[i+1][j]=='W')
             			{
             				i++;
             			}
             			else{
             				if(A[i+1][j]=='A')
             				{
             					flag=0;
             					break;
             				}
             			}
             	}
             }
       }
			
	}
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;	
	}		
	/* code */
	return 0;
       }
