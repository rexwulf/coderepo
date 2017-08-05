#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	long int k,day=0,n;
	cin>>n>>k;
	int w[n];
	for(int i=0;i<n;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
	{
		if(w[i]>=2*k)
			while(w[i]>=2*k)
			{
				w[i]-=2*k;
				day++;
			}

	}
	int i1=0,i2=0;
	while(!w[i1]&&i1<n) i1++;
	if(i1<n-1) i2=i1+1;
    else i2=i1;
    while(!w[i2]&&i2<n)
    	i2++;
   while((w[i1]||w[i2]) && i1<n && i2<n)
    {      	 if(w[i2]==0)
    	 i2=i1;
    	 if(w[i1]==0)
    	 i1=i2;
    	if(k>=w[i1]) { w[i1]=0; if(i1<n-1) i1++;}
    	else w[i1]-=k;
    	if(k>=w[i2]) { w[i2]=0; if(i2<n-1) i2++;}
    	else w[i2]-=k;
    	day++;
    	if(w[i1]==0) while(!w[i1]&&i1<n) i1++;
    	if(w[i2]==0) while(!w[i2]&&i2<n) i2++;
    	if(i2==i1){
    		if(i2<n-1)
    			{i2++;
    				while(!w[i2]&&i2<n-1) i2++;
    	    }
    	}
    }
    cout<<day;
return 0;
}