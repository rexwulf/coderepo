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
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repr(i,r,l) for(int i=r;i>l;i--)
#define all(x) x.begin(), x.end()
#define trace(x) cout<<" "<<#x<<"->"<<x
#define tracea(x,n) cout<<" "<<#x<<"=["; for(int i=0; i<n;i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define traced(x) cout<<" "<<#x<<"=["; for(int i=0; i<x.size();i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
using namespace std;
//---------------------------------------------------------------------------------------------------------------
ll T,k,n;
vector<int> A;

ll solve(){

    ll ans = 0;
    sort(A.begin(),A.end());
    //traced(A);
    for(int i=0,day=0;i<n;i++,day++){
        int con = 0;
        for(;i<n;i++){
            if(A[i]>day) con++,ans++;
            if(con==k) break;
        }
    }
    return ans;
}


int main(){
        cin>>T;
        rep(t,1,T+1){
            cin>>n>>k;
            A.resize(n);
            rep(i,0,n) cin>>A[i];
            cout<<"Case #"<<t<<": "<<solve()<<endl;
        }
	return 0;
}