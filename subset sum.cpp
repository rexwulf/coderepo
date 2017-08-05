#include<iostream>
using namespace std;
int nodes=0;

void printSubset(int A[],int n)
{   cout<<"\n\n";
	for(int i=0;i<n;i++)
    	printf("%*d", 5, A[i]);
}
void func(int A[], int solset[],int n, int size,int sum, int i,int const target)
{
	nodes++;
	
	for(int i=0;i<n;i++)
		cout<<solset[i];
	cout<<"  |  ";
	for(int i=0;i<size;i++)
		cout<<solset[i];
	if( target == sum )
	{
		// We found subset
		printSubset(solset, size);
		// Exclude previously added item and consider next candidate
		func(A, solset, n, size-1, sum - A[i], i + 1, target);
		return;
	}
	
	else
	{
		// generate nodes along the breadth
		for(int j ; j < size; j++ )
		{
			solset[size] = A[j];
			// consider next level node (along depth)
			func(A, solset, n, size + 1, sum + A[i], i + 1, target);
		}
	}
}


int main()
{
	int n, target;
	cin>>n;
	int A[n],B[n];
	for(int i=0;i<n;i++)
      cin>>A[i];
    cin>>target;

    func(A,B,n,0,0,0,target);
    
}