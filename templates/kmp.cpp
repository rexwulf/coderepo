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
ll m,n;
string s,t;

void kmp(const string &T, const string &P) {
  if (P.empty()) return;

  vector<int> pi(P.size(), 0), found_pos;
  for (int i = 1, k = 0; i < P.size(); ++i) {
    while (k && P[k] != P[i]) k = pi[k - 1];
    if (P[k] == P[i]) ++k;
    pi[i] = k;
  }

  cout<<endl;
  for (int i = 0, k = 0; i < T.size(); ++i) {
    while (k && P[k] != T[i]) k = pi[k - 1];
    if (P[k] == T[i]) ++k;
    if (k == P.size()) found_pos.pb(i - k + 1),k=pi[k-1];
  }

  for(auto i: found_pos)
    cout<<i<<"  ";
  //return -1;
}

int main(){
        string s,t;
        cin>>s>>t;
        kmp(t,s);
        cout<<endl;
        
	return 0;
}