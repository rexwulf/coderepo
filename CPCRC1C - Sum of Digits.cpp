#include<iostream>
#include<map>
using namespace std;


int main()
{
	long long int a,b,temp,hold;
	scanf("%lld %lld",&a,&b);

	while(a!=-1&&b!=-1)
	{
		long long int n=b-a+1,ans=0;
		map<long long int,long long int> sum;
		for(long long int i=a;i<=a+9 && i<=b;i++)
	      {  
             temp=i;
             sum[i]=0;
             while(temp)
             {
             	sum[i]+=(temp%10);
                temp/=10;
             }
             ans+=sum[i];
                          	cout<<"1. "<<i<<" "<<sum[i]<<"\n";

       	      }
         int flag;
         if(n>10)
	      for(long long int i=a+10;i<=b;i++)
	      { flag=0;
	      	
	      	if((i)%100==0)
	      	{ hold=i;
              for(;i<=hold+9 && i<=b;i++)
		      {  
	             temp=i;
	             sum[i]=0;
	             while(temp)
	             {
	             	sum[i]+=(temp%10);
	                temp/=10;
                 }
	             ans+=sum[i];   
	             cout<<"a2. "<<i<<" "<<sum[i]<<"\n";

	       	  }
flag=1;     i--;
	        }
	      	else
	      	{
	      	sum[i]=sum[i-10]+1;
	      	ans+=sum[i];
	        }
	        	   if(!flag)   	cout<<"2. "<<i<<" "<<sum[i]<<"\n";

	      }  
		cout<<ans<<"\n";
		cin>>a>>b;
	}
	/* code */
	return 0;
}