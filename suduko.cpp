#include<iostream>
using namespace std;
#define max 9
int n;

void printsol(int A[max][max])
{
  for(int i=0;i<n;i++)
  	{   cout<<"\n";
  		for(int j=0;j<n;j++)
  		cout<<A[i][j]<<" ";
    }
}

int isSafe(int A[max][max],int i,int j)
{  cout<<"yo1";
    for(int k=0;k<n;k++)   //row
    	if(k!=i && A[i][j]==A[k][j])
    		return 0;
    cout<<"yo2";	
    for(int k=0;k<n;k++)   //col
    	if(k!=j && A[i][j]==A[i][k])
    		return 0;	
    cout<<"yo3";
    int boxHor= j/3;             //finding the box's location in the Suduko grid
    int boxVer= i/3;

    for(int x=boxVer*3 ; x<boxVer*3+3 ; x++)
      for(int y=boxHor*3 ; y<boxVer*3+3 ; y++)
        if(x!=i && y!=j && A[x][y]==A[i][j])
          return 0;
   cout<<"\npassed:"<<A[i][j];
    return 1;      	
}

void findEmpty(int A[max][max],int &i,int &j)
{
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(A[i][j]==0)
				return;
}
int solve(int A[max][max])
{   
     int i,j;
    findEmpty(A,i,j);
       for(int k=0;k<9;k++)
       {
       	  A[i][j]=k+1;
       	 if(isSafe(A,i,j) && solve(A))
       	       return 1;
          A[i][j]=0;   	 
       }
    

       return 0;
    
}

int main()
{
	
	n=9;//cin>>n;
	int A[max][max] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};//int A[max][max];
	/*for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
		cin>>A[i][j];*/
    
    if(solve(A))
        printsol(A);
    else
    	cout<<"No solution";
	return 0;
}


/*
  3 0 6 5 7 8 4 9 2
  5 2 9 0 3 0 7 0 8
  4 0 7 6 2 9 0 3 1
  2 6 3 0 1 5 9 8 7
  9 7 0 8 6 0 1 2 5
  0 5 1 0 9 0 6 4 3
  1 3 8 9 4 7 2 5 6
  0 9 2 0 5 1 0 7 4
  7 4 5 2 8 6 3 1 9
*/