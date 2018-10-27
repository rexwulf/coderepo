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

class heap{
  public:
    int *A;
    int sz;
    int csz;
    heap(int n) : sz(n){  csz=0;  A = new int[sz];}
    int top();
    void push(int);
    void pop();
    void del(int);
    void heapify(int);
    void decrease(int,int);
    void fixtotop(int);
    void print();

    int par(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
};

void heap::print(){
  for(int i=0 ; i<csz ; i++) cout<<A[i]<<" ";
  cout<<endl;
}
int heap::top(){
  return A[0];
}
void heap::pop(){ //move last to top then heapify to bottom.
  A[0] = A[csz-1];
  heapify(0);
  csz--;
}
void heap::fixtotop(int i){ //swap till par becomes smaller than i
  while(i!=0 && A[par(i)] > A[i]){
    swap(A[par(i)], A[i]);
    i = par(i);
  }
}
void heap::push(int x){ //insert at bottom then fix to top
  csz++;
  A[csz-1] = x;
  fixtotop(csz-1);
}
void heap::decrease(int i,int val){ //update then fix to top
  A[i]=val;
  fixtotop(i);
}
void heap::heapify(int i){  //find smallest of i and 2 children, if a child is smaller swap and heapify that child i.e i now.
  int l = left(i), r = right(i), min_ = i;

  if(l<csz && A[l]<A[min_]) min_ = l;
  if(r<csz && A[r]<A[min_]) min_ = r;

  if(i != min_){ 
    swap(A[i],A[min_]);
    heapify(min_);
  }
}


int main() {
  heap h(5);
  h.push(5);
  h.push(10);
  h.push(25);
  h.print();
  h.pop();
  h.print();
  cout<<h.top()<<endl;
  return 0;
}