#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a,b,c,d,ans,first=2,second=2,i=1,term;
	float n1,n2;
	
		scanf("%d %d",&a,&b);
		scanf("%d %d",&c,&d);

		if((b%2==1)&&(a%2==0))
			first=0;
		if((b%2==0)&&(a%2==0))
			first=1;
		if((d%2==1)&&(c%2==0))
			second=0;
		if((d%2==0)&&(c%2==0))
			second=1;

		if(((first==1)&&(second==0)) || ((first==0)&&(second==1)))
		{
			cout<<"-1";
		    return 0;
		}
		
         term=b-a-d+c;

		while(1)
		{
            n2=float(term+i*a)/float(c);
           
            if((n2==int(n2))&&(n2>=0))
             break;
         i++;
        }    
		
		cout<<d+c*(n2-1);
	/* code */
	return 0;
}