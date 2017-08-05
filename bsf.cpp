    #include<iostream>
    #include<vector>
    #include<queue>
    #include<list>
    #include<cstdlib>
    using namespace std;

    int main()
    {
    	int t;
    	queue<int> q;

    	vector<list<int> > v(8);
    	vector<list<int> >::iterator it1;

    	list<int> it2;
        list<int>::iterator iter;

        bool visit[8];
        memset(visit,false,8);
        it1=v.begin();

    	v[0].push_back(1);
    	v[1].push_back(0);
    	v[1].push_back(2);
    	v[1].push_back(8);
    	v[1].push_back(3);
    	v[2].push_back(1);
    	v[2].push_back(4);
    	v[2].push_back(5);
    	v[3].push_back(1);
    	v[3].push_back(6);
    	v[4].push_back(2);
    	v[5].push_back(2);
    	v[5].push_back(7);
        v[6].push_back(3);
    	v[6].push_back(7);
    	v[7].push_back(5);
    	v[7].push_back(8);
    	v[8].push_back(1);
    	v[8].push_back(7);
        
        it1=v.begin();
        q.push(0);
        visit[0]=true;
        while(!q.empty())
        {    
        	t=q.front();
            q.pop();
        	it1=v.begin()+t;  //to start from the index of v[t]
        	it2=*it1;         //it2 copied the list v[t]={a,b,c,d...}
        	iter=it2.begin();
        		while(iter!=it2.end())
            	   {     if(!visit[t]) 
                          { q.push(*iter);
            			    cout<<" "<<t;
                            visit[*iter]=true;
                          }
                          
                         iter++;
        		   }
                   visit[t]=true;
                   
            it1++;
        }

    	return 0;
    }