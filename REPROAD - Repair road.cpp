#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{   
	int n,k,t,ans;
	cin>>t;
	while(t--)
	{	ans=-1;
		cin>>n>>k;
		int road[n],sum=0;
		vector<int> roady;
		for(int i=0;i<n;i++)
	     cin>>road[i];
	    for(int i=0;i<n;i++)
	    {   sum=0;
	    	
	    	while(road[i]&&i<n)
	    	  {sum+=road[i];
	    	  	if(road[i+1]&&i+1<n) i++;
	    	  	else break;
	    	  }
	        roady.push_back(sum);   
	    }
	    int size=roady.size(),flag,j;
	    for(int i=0;i<size;i++)
	    {   sum=0,flag=0;
	    	for(j=i;j<size&&flag<k;j++)
	        { if(roady[j]) sum+=roady[j];
              else{
               sum+=1;
               flag++;
               }
	        }
	        if(j<size&&roady[j])
	        	sum+=roady[j];
            ans=max(ans,sum);
	    }
	    cout<<ans<<"\n";	
	    
	}
	return 0;
}
