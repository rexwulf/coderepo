#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int findBad(int a,int A[],int n)
{
  for(int i=0;i<n;i++)
    if(A[i]==a)
      return 1;
  return 0;
}
int main()
{
	long int b,q,l,m,term,bad_i=0,ans=0;
  cin>>b>>q>>l>>m;
  term=b;
  int bad[m];
  for(int i=0;i<m;i++)
   cin>>bad[i];

  mergeSort(bad,0,m-1);
 
  if(q==1)
  {
    if(abs(b)<l)
    {
      if(findBad(b,bad,m)==0)
        cout<<"inf";
      else
        cout<<"0";
    }
    else cout<<"0";
    return 0;
  }
  long int c=0;
  if(abs(q)<1)
  {
    cout<<"inf";
    return 0;
  }
  vector<int> terms;
  while(abs(term)<l)
  { 
    terms.push_back(term);
    term*=q;
  }
  int term_size=terms.size();
  int i=0,j=0,flag,flag2;
      while (i < m && j < term_size)
    { flag=1; flag2=1;
        if (bad[i] < terms[j])
        {
            flag2=0;
            i++;
            flag=0;
        }
        
        if(bad[i]==terms[j])
        {
            flag=0;
            i++;
        }
        if(flag) ans++;
        if(flag2) j++;
    }





  cout<<ans+term_size-j;
	return 0;
}