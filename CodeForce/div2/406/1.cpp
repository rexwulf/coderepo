/*Ques:
A. The Monster
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A monster is chasing after Rick and Morty on another planet. They're so frightened that sometimes they scream. More accurately, Rick screams at times b, b + a, b + 2a, b + 3a, ... and Morty screams at times d, d + c, d + 2c, d + 3c, ....


The Monster will catch them if at any point they scream at the same time, so it wants to know when it will catch them (the first time they scream at the same time) or that they will never scream at the same time.

Input
The first line of input contains two integers a and b (1 ≤ a, b ≤ 100).

The second line contains two integers c and d (1 ≤ c, d ≤ 100).

Output
Print the first time Rick and Morty will scream at the same time, or  - 1 if they will never scream at the same time.

Examples
input
20 2
9 19
output
82
input
2 1
16 12
output
-1
Note
In the first sample testcase, Rick's 5th scream and Morty's 8th time are at time 82.

In the second sample testcase, all Rick's screams will be at odd times and Morty's will be at even times, so they will never scream at the same time.

*/

//rpSebestian
#include <bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for (int x=y;x<=z;x++)
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&b,&a,&d,&c);
	for (int i=0;;i++)
	{
		int x=a+b*i;
		if ((x-c) % d==0 && x>=c)
		{
			printf("%d\n",x);
			break;
		}
		if (i>1000000)
		{
			printf("-1\n");
			break;
		}
 	}

}



//taigob.reis
#include <bits/stdc++.h>

using namespace std;

bool vis[1000005];

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    while(b < 1000005) {
        vis[b] = true;
        b += a;
    }

    while(d < 1000005) {
        if (vis[d]) {
            printf("%d\n", d);
            return 0;
        }
        d += c;
    }

    printf("-1\n");
    return 0;
}