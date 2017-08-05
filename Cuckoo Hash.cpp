#include<iostream>
using namespace std;

int H1[11]={0},H2[11]={0}; //hash list 1 and hash list 2

void cuckoo(int a,int type)
{ int index,temp; 

  if(!type)   //type=0 means 1st hash list
  { 
  	 index=a%11;
  
   	if(!H1[index])
  	   H1[index]=a;
  
  	else
  	  { temp=H1[index];
  	  	H1[index]=a;
  	  	cuckoo(temp,1);

  	  } 
   }

   else    //type=1
   { 
	   	index=(a/11)%11;
	   	
	   	if(!H2[index])
	  	   H2[index]=a;
	  	
	  	else
	  	{  temp=H2[index];
	  		H2[index]=a;
	  	   cuckoo(temp,0);
	  	}
   }

 }

int main()
{   int A[]={20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
     
     int n=sizeof(A)/sizeof(A[0]);
     for(int i=0;i<n;i++)
      { 
      	cuckoo(A[i],0);
        cout<<"\n"<<i<<"------------------------------------\n";
            
        for(int i=0;i<11;i++)
        {
     	  if(H1[i]) cout<<"\t"<<H1[i];
     	  else cout<<"\t_";
        }
     
        cout<<"\n";
        for(int i=0;i<11;i++)
        {
     	   if(H2[i]) cout<<"\t"<<H2[i];
     	   else cout<<"\t_";
        }
     }

     
	return 0;
}
