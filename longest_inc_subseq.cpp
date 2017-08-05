#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int A[n],seq_len[n];
	vector<vector<int> > seq;
	seq.resize(n);

	for(int i=0;i<n;i++)
		{cin>>A[i];
         seq_len[i]=1;
     }
    
    int max=1,maxi=0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<i;j++)
    	{
           if(A[j]<A[i]&&seq_len[i]<=seq_len[j])
           	
           		{ 
           			seq_len[i]=seq_len[j]+1;
    	            seq[i].push_back(A[j]);
    	        }
    	}
    	
    	if(seq_len[i]>max) 
    		{ 
    			max=seq_len[i];  
    			maxi=i; 
    		}
    		cout<<" size:"<<seq_len[i];
	}
	cout<<"\n";



cout<<"ans:"<<endl;
	for(int i=0;i<seq[maxi].size();i++)
		cout<<" "<<seq[maxi][i];
     cout<<A[maxi];
	/* code */
	return 0;
}