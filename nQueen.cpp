#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> ans;

bool safe(int row,int col)
{
    if(row==0&&col==0)
        return true;
  for(int i=0;i<row;i++)
    if(ans[i]==col)
     return false;
  for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    if(ans[i]==j)
     return false;  
  for(int i=row,j=col;i>=0&&j<=n;i--,j++)
     if(ans[i]==j)
      return false;
   return true;          
}
bool nq(int row)
{   cout<<"\n--------------row="<<row;
    if(row>=n)
     return true;
    for(int j=0;j<n;j++)
    {  
        
            if(safe(row,j))

               { ans[row]=j;
                if(nq(row+1))
                   { 
                    cout<<"true";
                    return true;
                    }
                   ans[row]=0; 
                }    
       cout<<"\n safe="<<safe(row,j)<<" row="<<row<<"   col="<<j; 
    }
    cout<<"false";
return false;
}
int main()
{
 
    cin>>n;
    ans.resize(n+1);
    for(int i=0;i<=n;i++)
        ans[i]=0;
    if(nq(0))
        for(int i=0;i<ans.size();i++)
            cout<<" "<<ans[i];
    else cout<<"no ans available";
    return 0;
 }