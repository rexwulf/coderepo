#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t,temp,c1,c2,c,r,pf,pt;
	vector<int> from,to,avail,path1,path2;
	vector<int>::iterator it,it1 ,it2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&c,&r);
        temp=r;
        
        while(temp--)
        {
        	scanf("%d %d",&c1,&c2);
        	from.push_back(c1); 
        	to.push_back(c2);
        	avail.push_back(1);

        }
        pf=0,pt=0;
        int FLAG=1,flag1 , flag2;

        	for(int j=1; j<=c &&FLAG==1;j++)
        {   label1:
        	it=from.begin();
        	flag1=0;
        	pf=j;
        	while(it!=from.end())
        	{   if(*it==pf && avail[j]==1)
        		{
        			pf=to[j];
        			avail[j]=0;
        		    flag1=1;
        			break;

        		}
        		it++;
       		}
       		
       		it=to.begin();
       		flag2=0;
       		while(it!=to.end())
        	{   if(*it==pf && avail[j]==1)
        		{   flag2=1;
        			pf=to[j];
        			avail[j]=0;
        			break;
        		}
        		it++;
       		}
       		if(flag1==1||flag2==1) goto label1;

           if(pf!=j) {FLAG=0; break;}
           }
           if(FLAG==1) 
           	{
           		cout<<"yes!";
           		int p=0,j=1;
			           	   label2:
			        	it=from.begin();
			        	flag1=0;
			        	pf=j;
			        	path1.push_back(pf);
			        	p=1;
			        	while(it!=from.end())
			        	{   if(*it==pf && avail[j]==1)
			        		{
			        			pf=to[j];
			        			avail[j]=0;
			        		    flag1=1;
			        		    
			        		    path2.push_back(pf);
			        		    path1.push_back(pf);
			        			break;

			        		}
			        		it++;
			       		}
			       		
			       		it=to.begin();
			       		flag2=0;
			       		while(it!=to.end())
			        	{   if(*it==pf && avail[j]==1)
			        		{   flag2=1;
			        			pf=to[j];
			        			avail[j]=0;
			        			if(p)
			        		    path2.push_back(pf);
			        		    path1.push_back(pf);
			        			break;
			        		}
			        		it++;
			       		}
			       		if(flag1==1||flag2==1) goto label2;
			       		it1=path1.begin();
			       		it2=path2.begin();
			       		while(it2!=path2.end())
			       		{
			       			cout<<*it1<<" "<<*it2<<endl;
			       			it1++,it2++;
			       		}

           	}	
           else cout<<"no!";
           
        }
		
	
	/* code */
	return 0;
}