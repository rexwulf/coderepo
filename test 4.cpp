#include<iostream>
using namespace std;
 
int main()
{
        int t,winner,maxLead=-1;
        scanf("%d",&t);
        int S[2][t],L[2][10001]={0};
        for(int i=0;i<t;i++)
        {
                scanf("%d %d",&S[0][i],&S[1][i]);
 
                if(i)
                {
          if(L[0][i-1])
            {    
                    if(S[0][i]+L[0][i-1]>S[1][i])
                       L[0][i]=S[0][i]+ L[0][i-1]-S[1][i];
                    
                    else L[1][i]=S[1][i]-S[0][i]-L[0][i-1];
                }
               
               else
                {
                if(S[1][i]+L[1][i-1]>S[0][i])
                      L[1][i]=S[1][i]+ L[1][i-1]-S[0][i];
                    
                    else L[0][i]=S[0][i]-S[1][i]-L[1][i-1];
                }
                }
                else
                {
            if(S[0][i]>S[1][i])
              L[0][i]=S[0][i]-S[1][i];
            
            else L[1][i]=S[1][i]-S[0][i];
                }
                
                if(L[0][i]>maxLead||L[1][i]>maxLead)
          {
                winner=(L[0][i]>L[1][i])? 1 : 2;
                maxLead=L[winner-1][i];
      }
        cout<<"\n"<<S[0][i]<<" "<<S[1][i]<<" "<<maxLead;
        }
        cout<<winner<<" "<<maxLead<<"\n";
        /* code */
        return 0;
}