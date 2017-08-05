#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100010;
int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    int prv;
    scanf("%d",&prv);
    n--;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=abs(x-prv);
        prv=x;
    }
    ll sumev = 0, sumod = 0;
    ll best = 0;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            sumev+=a[i];
            sumod-=a[i];
        }
        else
        {
            sumev-=a[i];
            sumod+=a[i];
        }
        //printf("%lld %lld\n",sumev,sumod);
        sumev=max(sumev,0ll);
        sumod=max(sumod,0ll);
        best=max(best,sumev);
        best=max(best,sumod);
    }
    printf("%lld\n",best);
    return 0;
}