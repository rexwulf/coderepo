/* I can do this all day. Never Give Up! */
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vp vector<pair<int,int>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define trace(x) cout<<" "<<#x<<"->"<<x
#define tracea(x) n=sizeof(x)/sizeof(x[0]); cout<<" "<<#x<<"=["; for(int i=0; i<n;i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define traced(x) cout<<" "<<#x<<"=["; for(int i=0; i<x.size();i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
using namespace std;
//---------------------------------------------------------------------------------------------------------------
ll m,n,t,A[];

ll solve(){

}

int main(){
        cin>>t;
        while(t--){
            cin>>n;
            for(int i=0;i<n;i++)
                cin>>A[i];
            cout<<solve()<<endl;
        }
	return 0;
}