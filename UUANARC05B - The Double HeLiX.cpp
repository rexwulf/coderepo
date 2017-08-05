#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n1,n2;
	
	while(1)
	{   cout<<"enter n1:";
		scanf("%d",&n1);
		if(!n1) break;

		int c1[n1];
		for(int i=0;i<n1;i++)
          cin>>c1[i];
           
        cout<<"enter n2:";
        scanf("%d",&n2); 
        int c2[n2],A[n1][n2],c1sum[n1],c2sum[n2],c1index=0,c2index=0;  //c1sum->stores checkpoint sum of values of c1
        
        vector<int> common;
        for(int i=0;i<n1;i++)
         { 
           A[i][0]=0;
         } 
        for(int i=0;i<n2;i++)
         {
         	cin>>c2[i];
		    A[0][i]=0;
		 }

   for(int i=0;i<n2;i++)
 	cout<<"\n"<<i<<" "<<c2[i];

		for(int i=1;i<=n1;i++)
	       	for(int j=1;j<=n2;j++)
	    	 {   
	    		if(c1[i]==c2[j]) 
	    			A[i][j]=A[i-1][j-1]+1;
	    		else 
	    			A[i][j]=max(A[i-1][j],A[i][j-1]);
	    	 } 

for(int i=0;i<n2;i++)
 	cout<<"\n"<<i<<" "<<c2[i];
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
    	         common.push_back(c1[i]);
    	         
    	         i--,j--;
    	     }
    	}
    	
    	int ci=common.size()-1; //ci->common's present index
	    int check_sum=0;    
	     for(int i=0;i<n1;i++)
         { if(c1[i]==common[ci])
           { c1sum[c1index]+=(check_sum+c1[i]);
             cout<<"\n Checkpoint sum 1:"<<c1sum[c1index];
             check_sum=0;
             c1index++;
             ci--;
           }
           else check_sum+=c1[i];
         }   
      
         c1sum[++ci]=check_sum;
         ci=common.size()-1;
         check_sum=0;



       
        for(int i=0;i<n2;i++)
         { if(c2[i]==common[ci])
           { c2sum[c2index]+=(check_sum+c2[i]);
           	  cout<<"\n Checkpoint sum 2:"<<c2sum[c2index];
             check_sum=0;
             c2index++;
             ci--;
           }
           else check_sum+=c2[i];
           cout<<"\n "<<i<<" c2[i]"<<c2[i]<<" c2index"<<c2index<<" check_sum"<<check_sum<<" common[ci]"<<common[ci]<<" ci"<<ci;
         }
         c2sum[++ci]=check_sum; 
         int ans=0;
         cout<<"yah!";
         for(int i=0;i<=c1index;i++)
         {   if(c1sum[i]>c2sum[i])
         	  ans+=c1sum[i];
         	  else ans+=c2sum[i];

         }
         cout<<ans<<"\n";

	}
	/* code 13 3 5 7 9 20 25 30 40 55 56 57 60 62
            11 1 4 7 11 14 25 44 47 55 57 100
*/
	return 0;
}