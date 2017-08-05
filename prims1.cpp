#include<iostream>
#define for(i,j,n) for(int i=j;i<n;++i)
#define inf 1000008
using namespace std;
int v=5;
void prim(int G[][5])
{
  int key[v], parent[v] ,minm , u;
  bool inMST[5]={false} ;
  for(i,0,v)
    key[i]=inf;
  key[0]=0;
  parent[0]=-1;
  for(i,0,v-1)
  {  minm=inf;
     for(j,0,v)
       if(inMST[j]==false && key[j]<minm)
        minm=key[j],u=j;
     inMST[u]=true;

     for(j,0,v)
       if(G[u][j] && G[u][j]<key[j] && inMST[j]==false)
         key[j]=G[u][j], parent[j]=u;

     cout<<"\n";
     for(j,0,v) cout<<parent[j]<<" ";  
     cout<<"\n";
     for(j,0,v) cout<<key[j]<<" ";
     cout<<'\n';
     for(j,0,v) cout<<inMST[j]<<" ";
      cout<<"\n";
  }

  for(i,1,v-1)
    cout<<"\n"<<parent[i]<<" -> "<<i<<" :"<<key[i];  
}

int main()
{
  /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
  int G[5][5]={
            {0,2,0,6,0},
            {2,0,3,8,5},
            {0,3,0,0,7},
            {6,8,0,0,9},
            {0,5,7,9,0},   
            };
  prim(G);
return 0;
}