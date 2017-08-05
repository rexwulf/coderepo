#include<iostream>
#include<queue>
#include<vector>
#define inf 1000001
#define pii pair<int,int> 
#define for(i,j,n) for(int i = j; i < n; ++i)
using namespace std;
vector<vector<pii> > g; 
int V,E;

void mst()
{
 priority_queue<pii,vector<pii>,greater<pii> > q;
 pii p,v;
 vector<bool> inMST(V,false);
 vector<int> parent(V);
 vector<int> key(V,inf);

int src=0,u;
// Insert source in priority queue and initialize the wt to itself as 0
 q.push(make_pair(0,src));  //src->0 wt->0 

 while(!q.empty())
 {
 	p=q.top();
 	q.pop();
    int u=p.second, wt=p.first;

 	if(inMST[u]) continue;
    
    inMST[u]=true;
    for(i,0,g[u].size())
        {
          v=g[u][i];
         if(inMST[ v.second ]==false && v.first<key[ v.second ])
    	  { 
    	  	parent[v.second]=u;
    	  	key[v.second]= v.first;
            q.push(v);
          }
        }
  }
 for(i,1,V)
  cout<<"\n"<<parent[i]<<"->"<<i<<" "<<key[i]; 
}    

int main() {
	int a,b,wt;
	cin>>V>>E;
	g.resize(V);
    for(i,0,E)
    { cin>>a>>b>>wt;
      g[a].push_back(make_pair(wt,b));
      g[b].push_back(make_pair(wt,a));
    }
    mst();
    return 0;
}
/*

 Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          
INPUT:
 5 7
0 1 2
1 2 3
0 3 6
1 3 8
1 4 5
2 4 7
3 4 9

OUTPUT:
0->1 2
1->2 3
0->3 6
1->4 5
*/