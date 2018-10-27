/* Cool and calm will take over the world. 
    -Rishabh Bharti */
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

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];  
}

void update(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) 
    t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++]; //adds and moves to its cousin then in cousin's parent in next iteration. l---_^_-----_^_------r
    if (r&1) res += t[--r]; //always adds the even indexed element on its left.
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  update(0, 1);
  printf("%d\n", query(2,6));
  return 0;
}