#include<iostream>
using namespace std;
int max_spam(int *arr,int n)
{
    int count=0;
   for(int i=0;i<n;i++)
   {
       if(arr[i]==0)
       arr[i]=1;
       else
       count++,arr[i]=-1;
   }
   if(count==n)
   return n;
   int ans=-1,currmax=0;
   
   for(int i=0;i<n;i++)
   {
       currmax=max(arr[i],arr[i]+currmax);
       ans=max(ans,currmax);
   }
  
   return (count+ans);
   
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<max_spam(arr,n)<<endl;
    }
}