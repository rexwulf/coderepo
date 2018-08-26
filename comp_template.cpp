/* I can do this all day. Never Give Up! */
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define vp vector<pair<int,int>
#define vvi vector<vi>
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define inf 1e6
#define MOD 1e9+7
#define rep(i,l,r) for(int i=l;i<r;i++)
#define rrep(i,r,l) for(int i=r;i>l;i--)
#define all(x) x.begin(), x.end()
#define trace(x) cout<<" "<<#x<<"->"<<x
#define tracea(x,n) cout<<" "<<#x<<"=["; for(int i=0; i<n;i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define traced(x) cout<<" "<<#x<<"=["; for(int i=0; i<x.size();i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
using namespace std;
//---------------------------------------------------------------------------------------------------------------
ll t,m,n,A[105];

ll solve(){
    
}

int main(){
        cin>>t;
        while(t--){
            cin>>n;
            rep(i,0,n) cin>>A[i];
            cout<<solve()<<endl;
        }
	return 0;
}
