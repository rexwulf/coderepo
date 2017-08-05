#include <iostream>
using namespace std;

int main() {
    int mino,temp,A[10],B[10],n,size=0,r,a,b;
    cin>>n;
    temp=n;

    while(temp)
    {
      r=temp%10;
      B[size++]=r;
      temp/=10;
    }

    
    for(int j=0;j<size;j++)
    {
    	A[j]=B[size-j-1];
    }
   temp=A[size-1];
   int j=size-2;
   while(A[size-1]<A[j])
       j--;
   mino=size-1-j;

   for(int i=size-2;i>0;i--)
   {
   	 for(j=i-1;j>=0;j--)
   	 {
   	 	if(A[i]>A[j])
   	 	{
   	 		if(i-j<mino)
   	 		{
   	 			mino=i-j;
                a=j;
                b=i;
                i=0;
                break;
   	 		}
   	 	}
   	 }
   }
   temp=A[a];
   A[a]=A[b];
   A[b]=temp;

   cout<<"\n";
   for(int i=0;i<size;i++)
    cout<<A[i];

  return 0;
}

