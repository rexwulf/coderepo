#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define long long int ll
using namespace std;
int parent[100];
vector<pair<int,pair<int,int> > > e;
vector<pair<int,pair<int,int> > >::iterator it;

int findParent(int x)
{
	while(parent[x]!=x)
	{  parent[x]=parent[parent[x]];
	   x=parent[x];
	}
    return x;
}


int kruskal(vector<pair<int,pair<int,int> > > e)
{
  it=e.begin();	
  pair<int,pair<int,int> > p;
  int a,b,w,mincost=0;
  while(it!=e.end())
  { p=*it;
    w=p.first;
    a=p.second.first;
    b=p.second.second;
    if(findParent(a)!=findParent(b))
    {
      mincost+=w;
      parent[findParent(a)] = parent[findParent(b)]; //joining the 2 vertices i.e linking the nodes as parent
    }
  	it++;
  }
  return mincost;
}

int main()
{
	int nodes,edges,a ,b ,w;
	cin>>nodes>>edges;
    cout<<endl;
	for(int i=0;i<nodes;i++)  //initialize the parent of a node to the node's value
		parent[i]=i;

	for(int i=0;i<edges;i++)  // edge input i.e from a->b with weight w;
	{
		cin>>a>>b>>w;
		e.push_back(make_pair(w,make_pair(a,b)));
    }
    
    sort(e.begin(),e.end());
 
    cout<<"\n the min cost of spanning tree is: "<<kruskal(e);
	return 0;
}