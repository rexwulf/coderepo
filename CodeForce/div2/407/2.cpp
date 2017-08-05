#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, int> bad;
int main()
{
    ll b1,q,l,m;
    scanf("%lld%lld%lld%lld",&b1,&q,&l,&m);
    while(m--)
    {
        ll x;
        scanf("%lld",&x);
        bad[x]++;
    }
    ll ans = 0;
    int cnt = 0;
    while(llabs(b1)<=l&&cnt<100000)
    {
        ++cnt;
        if(!bad[b1]) ans++;
        b1*=q;
    }
    if(ans > 2000) puts("inf");
    else printf("%lld\n",ans);
    return 0;
    
    if(b1==0)
    {
        if(bad[0]) puts("0");
        else puts("inf");
    } 
    else
    if(q==0)
    {
        ll ans = 0;
        if(!bad[b1]) ans++;
        if(!bad[0]) puts("inf");
        else printf("%lld\n",ans);
    }                                                                         
    else if(q==1)
    {
        if(bad[b1]) puts("0");
        else puts("inf");
    }
    else if(q==-1)
    {
        if(bad[b1]&&bad[-b1]) puts("0");
        else puts("inf");
    }
    else
    {
        ll ans = 0;
        while(llabs(b1)<=l)
        {
            if(!bad[b1]) ans++;
            b1*=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}