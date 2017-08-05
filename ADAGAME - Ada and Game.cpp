#include<iostream>
#include<cstring>
using namespace std;
int a , turn, dp[10001][101];

int calc(int num,int i)
{   int ten=1,temp=num, digit;

	if(i==0)              //base case , checking the resultant number when turns left->0
		return num>a;

    if(dp[num][i]!=-1)    
    	return dp[num][i];
    
    dp[num][i]=0;   
    if(( turn%2==0 && i%2==0 ) || ( turn%2==1 && i%2==1 )) //ADA's chance
    {         //ADA wins when she gets "true" for any dp[][] so we use '|'
      while(ten<10000)           //to increase digits 
      {
      	digit=temp%10;       
        
        if(digit==9)        //converting 9->0
        	dp[num][i]= dp[num][i] | calc( num-9*ten ,i-1 );
        else                //converting others
        	dp[num][i]= dp[num][i] | calc( num+ten , i-1 );
        temp/=10;
        ten*=10;     // we are approaching digits from LSB to MSB
      }
    }

   else //ADA's chance
//VINIT's chance
    { dp[num][i]=1; 
      while(ten<10000)          
       {
      	digit=temp%10;       
        
        if(digit==9)    //VINIT wins when ADA doesn't get "true" for any dp[][] so we use &   
        	dp[num][i]= dp[num][i] & calc( num-9*ten ,i-1 );
        else               
        	dp[num][i]= dp[num][i] & calc( num+ten , i-1 );
        temp/=10;
        ten*=10;    
       }
    }
    return dp[num][i];
 }


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{	memset(dp,-1,sizeof(dp));
		scanf("%d %d",&a,&turn);
		if(calc(a,turn)) 
			cout<<"Ada\n";
		else 
			cout<<"Vinit\n";
	}
	/* code */
	return 0;
}

