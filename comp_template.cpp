#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define trace(x) cout<<" "<<#x<<"->"<<x
#define traced(x) cout<<" "<<<#x<<"=["; for(auto i: x) cout<<" "<<i; cout<<" ]"
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
typedef long long ll;
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