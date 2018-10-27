#include <bits/stdc++.h>
 
using namespace std;
 
const long long INFLL = 1000000000000000000ll;
int N;
long long DP[1100000][25], X[25], Y[25];
 
int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
 
    for(int m = 1; m < (1<<N); m++) for(int i = 0; i < N; i++) DP[m][i] = INFLL;
    for(int i = 0; i < N; i++) DP[1<<i][i] = 0;
 
    for(int m = 1; m < (1<<N); m++)
        for(int i = 0; i < N; i++)
            for(int b = 0; b < N; b++)
                if(!(m&(1<<b)))
                    DP[m+(1<<b)][b] = min(DP[m+(1<<b)][b], abs(X[b]-X[i]) + abs(Y[b]-Y[i]) + DP[m][i]);
 
    long long ans = INFLL;
    for(int i = 0; i < N; i++) ans = min(ans, DP[(1<<N)-1][i]);
    cout << ans << "\n";
}
