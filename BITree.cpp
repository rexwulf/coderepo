/*
construct : nlogn
update : logn
range sum query : logn
*/

#include<iostream>
using namespace std;

void updateBIT(int b[],int n,int i,int val)
{
	i++;    //in BIT the index is 1 more than the index
	while(i<=n)
	{
		b[i]+=val;
		i += (i & -i);    //-i is 2's complement of i , do some maths on copy
	}
}

int getsum(int b[],int i,int j)
{
  if(i!=0)
  {
  	return getsum(b,0,j) - getsum(b,0,i-1);
  }

  int sum=0;
  j++;
  while(j>0)
  {
    sum+=b[j];
    j -= (j&-j);  //to get parent we have to flip the rightmost 1.
  }
  return sum;
}


int main()
{
	int arr[]={2,1,1,3,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(arr[0]);
    int BIT[n+1];
    for(int i=0;i<n+1;i++)
    	BIT[i]=0;

    for(int i=0;i<n;i++)
    	updateBIT(BIT,n,i,arr[i]);

     for(int i=1;i<=n;i++)
		cout<<"  "<<BIT[i];

    cout<<"   "<<getsum(BIT,2,4); // 1 + 3 + 2 = 6  don't connfuse b/w index of array and BIT
    return 0;
}