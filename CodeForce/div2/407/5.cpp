#include <bits/stdc++.h>
using namespace std;
set<int> has;
const int inf = 1010;
vector<int> le;
vector<int> up;
int sol[1000010][2];
void knapsack(vector<int> w, int idx)
{
    for(int i=1;i<=1000000;i++) sol[i][idx]=inf*inf;
    for(int i=0;i<=1000000;i++)
    {
        for(int j=0;j<w.size();j++)
        {
            if(w[j]<=i) sol[i][idx]=min(sol[i][idx], 1 + sol[i-w[j]][idx]);
        }
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int mini = inf;
    int maxi = -inf;
    while(k--)
    {
        int x;
        scanf("%d",&x);
        has.insert(x);
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    //printf("%d %d\n",mini,maxi);
    if(n < mini || n > maxi)
    {
        puts("-1");
        return 0;
    }
    bool imm = false;
    for(auto &x : has)
    {
        if(x==n)
        {
            imm = true;
            break;
        }
        if(x<n) le.push_back(n-x);
        else if(x>n) up.push_back(x-n);
    }
    if(imm)
    {
        puts("1");
        return 0;
    }
    sort(le.begin(),le.end());
    sort(up.begin(),up.end());
    knapsack(le,0);
    knapsack(up,1);
    int ans = inf*inf*inf;
    //for(int i=0;i<=1000;i+=50) printf("%d %d\n",sol[i][0],sol[i][1]);
    for(int i=1;i<=1000000;i++) ans=min(ans, sol[i][0]+sol[i][1]);
    printf("%d\n",ans);
    return 0;
}