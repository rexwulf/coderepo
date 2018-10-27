/* NO FUCKS GIVEN, MIND == BLOWN */
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

ll t, n, ans, M = 1ll*(1e9+7);
vi A, cnt;

ll gcd(ll a, ll b){
    if(b==0)    return a;
    return gcd(b,a%b);
}


//For O(1) query
int C[100005][100005];

int nCr(int n, int r){              
    if(n==r || r==0) return C[n][r] = 1; //Base Case
    if(r==1) return C[n][r] = n;

    if(dp[n][r]) return C[n][r]; // Using Subproblem Result
    return C[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%M;
}


//+ for smaller r and larger n
ll nCr(ll N, ll r) { 
    if(N<r || r<0 || N<0)   return 0;
    ll res = 1; 
    r=min(r,N-r); 
    for (int i=0; i<r; i++)     res = (res * (N-i))%M;                      // Calculate value of [n * (n-1) *---* (n-r+1)] / [r * (r-1) *----* 1] 
    for (int i=0; i<r; i++)     res = (res * modInverse(i+1))%M;
    return res; 
} 

int F[100005];

ll fact(ll x){
    if(F[x])   return F[x];
    ll ans = 1;
    for(int i=2 ; i<=x ; i++)   ans = (ans*i)%M, F[i]=ans;
    return ans;
}



ll power(ll x, ll n){
    if(n==1)    return x;

    ll ans = power(x,n/2);
    ans = (ans*ans)%M;

    if(n%2) ans = (ans * x)%M;
    return ans;
}

//modular multiplicarive inverse so don't do Nr%p/Dr%p (wrong), instead do Nr%p * Dr^-1 %p
ll modinv(ll a){        
    if(gcd(a,M)==1) return power(a,M-2);    //Fermat's little theorem : a^-1 = a^(M-2) % M       where a and M are co-prime
    else              return -1; //DNE
}



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

}