/* Cool and calm will take over the world. 
    -Rishabh Bharti */
#pragma region
#ifndef BZ
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#endif
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define f first
#define s second
#define debugs(x) cout<<" "<<#x<<"=["; for(int i=0; i<x.size();i++) cout<<" "<<x[i]; cout<<" ]"
#define debug(args...) { cout<<__LINE__<<": "; string s = #args; istringstream ss(s); err(ss, args); }
void err(istringstream &ss) { cout<<"\n"; }
template<typename T, typename... Args>
void err(istringstream &ss, const T &a, const Args & ... args) {
    string token;
    getline(ss, token, ',');
    cout << token << " = " << a << "; ";
    err(ss, args...);
}
//--------------------------------------------------------------------------------------------------------------------------------
#pragma endregion

ll t,m,n;
vi A;

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin>>n;
    A.resize(n);
    for(int i=0 ; i<n ; i++) cin>>A[i];
    solve();
	return 0;
}