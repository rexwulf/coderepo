#include<iostream>
using namespace std;

struct weapon
{
   int openCost[21];
   int weaponCost[21][21];
   int power[21][21];
    effective(21,vector<int>(21));
};
int main()
{
	int t,n,m,k;
	scanf("%d",&t);
	while(t--)
	{   struct weapon w;
		scanf("%d %d %d",&n,&m,&k);
		for(int i=0;i<n;i++)
            cin>>w.openCost[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>w.weaponCost[i][j];

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
		       { cin>>w.power[i][j];
                 w.effective[i][j]=w.power[i][j]/w.weaponCost[i][j];
		       }
	}
	/* code */
	return 0;
}