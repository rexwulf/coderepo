#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int cnt = 0;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        cnt += (x+k-1)/k;
    }
    printf("%d\n",(cnt+1)/2);
    return 0;
}