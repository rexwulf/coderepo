#include<iostream>
#include<vector>
using namespace std;


void merge(vector<long long int> arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    vector<long long int>  L(n1), R(n2);

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
    return;
 }


void mergeSort(vector<long long int> arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int l, int r, int x)
{ char ch='o';
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    // Check if x is present at mid
    if (arr[m] == x) 
        return m;  
 
    // If x greater, ignore left half  
    if (arr[m] < x) 
        { l = m + 1; 
          if(ch=='b') return m;
          ch='c';
        }
 
    // If x is smaller, ignore right half 
    else
         { r = m - 1;
            if(ch=='c') return m-1;
           ch='b';
         } 
  }
 
  // if we reach here, then element was not present
  return -1; 
}

int main()
{int A[]={1,2,2,2,2,3,4,7,9};
int t,a;
cin>>t;
while(t--)
{cin>>a;
  cout<<binarySearch(A,0,8,a)<<endl;}
	return 0;
}
