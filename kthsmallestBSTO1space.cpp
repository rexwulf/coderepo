#include <iostream>
using namespace std;

int main() {
    int t,n,count,flag;
    cin>>t;
    while(t--)
    { cin>>n;
      count=flag=0;
      char A[n][2];
      int safe[n][2];
      for(int i=0;i<n;i++)
       cin>>A[i][0];
      for(int i=0;i<n;i++)
       cin>>A[i][1];
      for(int i=0;i<n;i++)
        safe[i][0]=safe[i][1]=0;
      safe[0][0]=safe[0][1]=1;
      for(int i=0;i<n;i++)
      {
        if(A[i][0]=='*')
        {
           if(i&& safe[i-1][0]==0 && !safe[i][0])
           {
            count++; 
            safe[i][0]=safe[i][1]=1; 
           }

           if(i!=n-1 && A[i+1][0]=='*')
           {
             count++; 
             safe[i+1][0]=safe[i+1][1]=1; 
           }
           if(A[i][1]=='*' && !flag)
           {
            count++; 
            safe[i][0]=1;
            flag=1;
           }
           if(i!=n-1 && A[i+1][1]=='*' && !flag)
           {
            count++; 
            safe[i][0]=1;
            flag=1;
           }
        }

        if(A[i][0]=='.')
        {
           if(i && safe[i-1][0]==1 && A[i-1][0]!='*')
             safe[i][0]=1; 

        }

        if(A[i][1]=='*')
        {   if(i && safe[i-1][1]==0 && !safe[i][1])
             {
              count++;   
              safe[i][1]=safe[i][0]=1; 
             }
             if(i!=n-1 && A[i+1][1]=='*' && !safe[i+1][1])
             {
              count++;    
              safe[i+1][0]=safe[i+1][1]=1; 
             }
             if(i!=n-1 && A[i+1][0]=='*' && !safe[i+1][0] && !flag)
             {
              count++;
              flag=1;    
              safe[i+1][0]=1; 
             }

        }

        if(A[i][1]=='.')
        {  
             
          if(i && safe[i-1][1]==1 && A[i-1][1]!='*')
             safe[i][1]=1;   
        }
        
       
      }
  cout<<count<<"\n";
    }
  return 0;
}

