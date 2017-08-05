#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int A[],int low,int high)
{
  int i=low-1;

  for(int j=low;j<high;j++)
  {
    if(A[j]<A[high])
    {
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(&A[i+1],&A[high]);
  return i+1;
}

void quicksort(int A[],int low,int high)
{
  if(low<high)
  {
    int pivot=partition(A,low,high);
    
    quicksort(A,low,pivot-1);
    quicksort(A,pivot+1,high);
  }
}
int main()
{
  int A[]={10,80,30,90,40,50,70};
  int n=sizeof(A)/sizeof(A[0]);
  quicksort(A,0,n-1);
  for(int i=0;i<n;i++)
    cout<<" "<<A[i];
  return 0;
}