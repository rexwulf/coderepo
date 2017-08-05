#include<iostream>
#include<queue>
#include<vector>
#define inf 1000001
#define pii pair<int,int>      //first->wt , second->dest
#define for(i,j,n) for(int i = j; i < n; ++i)
using namespace std;
vector<vector<pii> > g; 
int V,E;

void make_path(vector<int> parent,int i)
{  if(parent[i]==-1) return;
   else cout<<"<-"<<parent[i];
   make_path(parent,parent[i]);
}
void mst()
{
 priority_queue<pii,vector<pii>,greater<pii> > q;
 pii p,v;
 vector<bool> inMST(V,false);
 vector<int> distance(V,inf);
 vector<int> parent(V,-1);
 distance[0]=0;
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
       {                  //src distance-> already calc distance from src to prev node + edge wt b/w u & v             
            v=g[u][i];                   //prev.first+v.first<distance[v.second]-> checks if the src distance is smaller from v
           if(distance[u] + v.first< distance[ v.second ]) //v.first-> checks if 2 nodes are connected
      	   { 
      	  	distance[v.second]= distance[u] + v.first;
            parent[v.second]=u;
            q.push(v);
           }
        }
        
  }
 for(i,1,V)
 {  cout<<"\n";
    cout<<i<<" "<<distance[i]<<" "<<i; 
    make_path(parent,i);
  }
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