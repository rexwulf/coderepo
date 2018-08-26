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
#define rrep(i,r,l) for(int i=r;i>l;i--)
#define all(x) x.begin(), x.end()
#define trace(x) cout<<" "<<#x<<"->"<<x
#define tracea(x) n=sizeof(x)/sizeof(x[0]); cout<<" "<<#x<<"=["; for(int i=0; i<n;i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define traced(x) cout<<" "<<#x<<"=["; for(int i=0; i<x.size();i++) cout<<" "<<x[i]<<"("<<i<<")"; cout<<" ]"
#define fill1d(x,val) memset(x,val,sizeof(x))
#define fill2d(x,val) fill_n(*x, sizeof(x)/sizeof(**x),val);
using namespace std;
//---------------------------------------------------------------------------------------------------------------
ll T,mx,n,p;
vector<string> A;
vi z,o,cost;
map<string,bool> m;


class gnode{
    public:
    string str;
    int cost;
    int cur;
    gnode(string s,int c,int ind){
        this->str=s;
        this->cost=c;
        this->cur=ind;
    }
};

void calc(int i){
    rep(j,0,p){
        if(A[i][j] == '0') z[j]++;
        else o[j]++;
    }
}

bool isValid(string s){
    return m.find(s)==m.end();
}

void alt(char& c){
    if(c=='0') c='1';
    else c='0';
}

class comp{
    public:
    bool operator() (gnode a,gnode b){
        return a.cost>b.cost;
    }
};

ll make_graph(gnode start){
    priority_queue<gnode, vector<gnode> , comp> pq;
    pq.push(start);
    gnode x("",0,0);

    int node_seen=0;

    while(node_seen<100){
        x = pq.top(); pq.pop();
        //trace(x.str),trace(x.cost),trace(x.cur),cout<<endl;
        node_seen++;
        //cout<<"\nPopped: "<<x.str<<endl;
        if(isValid(x.str))
            return x.cost;
        
        rep(i,x.cur,p){
            alt(x.str[i]);
            //cout<<"\npushed: "<<x.str<<" "<<x.cost + cost[i]<<" "<<x.cur+1;
            pq.push(gnode(x.str,x.cost + cost[i],i+1));
            alt(x.str[i]);
        }
    }
    z.clear(),o.clear();
    return pq.top().cost;
}

ll solve(){
    rep(i,0,n) calc(i);

    string init_string = "";
    int init_cost=0;

    rep(i,0,p){
        cost[i] = abs(z[i]-o[i]);

        init_string += (z[i] > o[i] ? '0' : '1' );

        init_cost += min(z[i],o[i]);
    }

    //trace(init_cost), trace(init_string);
    if(isValid(init_string)) return init_cost;
    return make_graph(gnode(init_string,init_cost,0));
}


int main(){
        string s;
        cin>>T;
        rep(t,1,T+1){
            cin>>n>>mx>>p;
            z.clear(),o.clear(),cost.clear(),m.clear();
            A.resize(n), z.resize(p,0), o.resize(p,0), cost.resize(p);
            
            rep(i,0,n) cin>>A[i];
            rep(i,0,mx) cin>>s,m[s]=1;
            cout<<"Case #"<<t<<": "<<solve()<<endl;
        }
	return 0;
}