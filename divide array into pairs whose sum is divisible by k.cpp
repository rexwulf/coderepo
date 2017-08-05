// A C++ program to check if arr[0..n-1] can be divided
// in pairs such that every pair is divisible by k.
#include <bits/stdc++.h>
using namespace std;

// Returns true if arr[0..n-1] can be divided into pairs
// with sum divisible by k.
bool canPairs(int arr[], int n, int k)
{
    int sum = 0;
  for(int i=0;i<n;i++) {
      sum+=arr[i];
  }
  return (n%2==0 && sum%(n/2*k)==0) ? 1 : 0;   //{9,5,7,3} then since there are 2 pairs, total sum should be 2*k for it to return true;  
}

/* Driver program to test above function */
int main()
{
//  int arr[10];
for(int i=0;i<10;i++)
 cin>>arr[i];
 int k = 10;
  int n = sizeof(arr)/sizeof(arr[0]);
  canPairs(arr, n, k)? cout << "True": cout << "False";
  return 0;
}
