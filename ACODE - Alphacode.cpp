#include<iostream>
#include<string>
using namespace std;


void calc(int A[5000],int i,long long int p[5000])
{  
    if(A[i]) p[i]=p[i-1];                     //to avoid the case when 0 is used 
                                              //as a seperate no. to decode to alphabet
    int no=10*A[i-1]+A[i];
   if((no>9&&no<=26))
   	{  
   		if(!(i-1)) 
   			p[i]+=1;

   	    else	
   	  	  p[i]+=p[ i-2<0 ? 0 : i-2];             //to avoid out of bound when
    }                                            //in the function call for i=1, p[i-2] is checked 
}

void func(int A[5000],int i,int n,long long int p[5000])
{
	for(int i=1;i<n;i++)                          //bottom-up dp approach
		calc(A,i,p);
		
}
int main()
{
	int a ,A[5001],len;	
	string str;
	while(true)
	{    cin>>str;
         len=str.size();
         long long int p[5001]={0};      //initialising all permutations to 0

         for(int i=0;i<len;i++)
         A[i]=str[i]-'0';                 //converting string to int array

         if(!A[0]) break;                   
		  p[0]=1;
		  func(A,0,len,p);
		  cout<<"\n"<<p[len-1];
		
	}
	/* code */
	return 0;
}