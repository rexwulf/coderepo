#include<bits/stdc++.h>
#include <stdio.h>
#define INF LONG_MAX-100
#include<algorithm>
typedef long long ll;
using namespace std;
ll n;   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
      ll q;
      cin>>n>>q;
      ll a[n];
      for(j=0;j<n;j++)
      cin>>a[j];
      sort(a,a+n);
      ll dp[n+1];
    dp[n]=0;
    for(j=n-1;j>=0;j--)
    dp[j]=a[j]+dp[j+1];
      for(k=0;k<q;k++)
    {ll q1;
    cin>>q1;
         
    ll c=0;
    ll ind=lower_bound(a,a+n,q1)-a;
    c+=(n-ind);
    ll z=ind;
    ll w=dp[ind];
  /*  ll diff[ind;
    ll dp[ind-1];
       for(j=0;j<ind;j++)
     diff[j]=q1-a[j];
     dp[ind-1]=diff[ind-1];
     for(j=ind-2;j>=0;j--)
      dp[j]=dp[j+1]+diff[j];*/
      ll l=0;ll h=ind-1;
      ll ans=0;
  while(l>=0&&h<=ind-1&&l<=h)
  { 
  ll mid=(l+h)/2;
  if((z-mid)*q1-(dp[mid]-w)<=mid)
    {
      ans=max(ans,ind-mid);
      h=mid-1;
    }
    else
    l=mid+1;
}
cout<<ans+c<<endl;
     
     
}
}
return 0;
}