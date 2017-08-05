/*
Representation:
 For 4 adjacency lists of 4 nodes (0,1,2,3) and edges: (0-1,1-2,1-3,2-0,2-1,2-3,3-2)
 define lis[4] then: v=4
 
        
 lis[0]-> (head)1 ->x
 lis[1]-> (head)2 -> 3 ->x
 lis[2]-> (head)0 -> 1 -> 3 ->x
 lis[3]-> (head)2 ->x
  
*/


#include<iostream>
using namespace std;


//----------------------------NODE-------------------------------------------
struct node
{
    int data;
    struct node* next;
};

struct node* newNode(int v)
{
    struct node* me = (struct node*)malloc(sizeof(struct node));
    me->data = v;
    me->next = NULL;
    return me;
}
//----------------------------GRAPH-------------------------------------------
class graph
{
	 public:

	    int v;
	    struct node** lis;

	 graph(int a)
	 {
	    v = a;
	    lis = (struct node**)malloc(v * sizeof(struct node*));
	 
	    for (int i = 0; i < v; i++)
	        lis[i] = NULL;
	 
	  }
	 
	void addEdge(int u, int v)
	{
	   
	    node* me = newNode(v);
	    me->next = lis[u];  //inserting at head of linked list
	    lis[u] = me;

	/* For adding reverse edge in undirected graph
	    me = newNode(u);
	    me->next = graph->lis[v];
	    graph->lis[v] = me;
	 */   
	}
	 
	void printGraph()
	{
		struct node* temp=NULL ;

	    for (int i=0 ;i<v ;i++)
	    {
	        temp = lis[i];
	        cout<<"\n Adjacency list "<<i<<" : ";
	        while (temp)
	        {
	        	cout<< temp->data <<" -> ";
	          temp=temp->next;
	        }
	          
	    }
	}

};
//----------------------------------MAIN------------------------------------

int main()
{
	graph g(6);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);   
    g.addEdge(4, 6);
    g.addEdge(5, 1);
    g.addEdge(5, 6); 
    g.printGraph();
	return 0;
}