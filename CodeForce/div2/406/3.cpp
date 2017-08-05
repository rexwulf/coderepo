/*Question:
C. Berzerk
time limit per test4 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Rick and Morty are playing their own version of Berzerk (which has nothing in common with the famous Berzerk game). This game needs a huge space, so they play it with a computer.

In this game there are n objects numbered from 1 to n arranged in a circle (in clockwise order). Object number 1 is a black hole and the others are planets. There's a monster in one of the planet. Rick and Morty don't know on which one yet, only that he's not initially in the black hole, but Unity will inform them before the game starts. But for now, they want to be prepared for every possible scenario.


Each one of them has a set of numbers between 1 and n - 1 (inclusive). Rick's set is s1 with k1 elements and Morty's is s2 with k2 elements. One of them goes first and the player changes alternatively. In each player's turn, he should choose an arbitrary number like x from his set and the monster will move to his x-th next object from its current position (clockwise). If after his move the monster gets to the black hole he wins.

Your task is that for each of monster's initial positions and who plays first determine if the starter wins, loses, or the game will stuck in an infinite loop. In case when player can lose or make game infinity, it more profitable to choose infinity game.

Input
The first line of input contains a single integer n (2 ≤ n ≤ 7000) — number of objects in game.

The second line contains integer k1 followed by k1 distinct integers s1, 1, s1, 2, ..., s1, k1 — Rick's set.

The third line contains integer k2 followed by k2 distinct integers s2, 1, s2, 2, ..., s2, k2 — Morty's set

1 ≤ ki ≤ n - 1 and 1 ≤ si, 1, si, 2, ..., si, ki ≤ n - 1 for 1 ≤ i ≤ 2.

Output
In the first line print n - 1 words separated by spaces where i-th word is "Win" (without quotations) if in the scenario that Rick plays first and monster is initially in object number i + 1 he wins, "Lose" if he loses and "Loop" if the game will never end.

Similarly, in the second line print n - 1 words separated by spaces where i-th word is "Win" (without quotations) if in the scenario that Morty plays first and monster is initially in object number i + 1 he wins, "Lose" if he loses and "Loop" if the game will never end.

Examples
input
5
2 3 2
3 1 2 3
output
Lose Win Win Loop
Loop Win Win Win
input
8
4 6 2 3 4
2 3 6
output
Win Win Win Win Win Win Win
Lose Win Lose Lose Win Lose Lose
*/


//rpSebestian
#include <bits/stdc++.h>
using namespace std;
#define rep(x,y,z) for (int x=y;x<=z;x++)

int n;
const int N=10008;
int a[N],b[N],ta,tb,time_a[N],time_b[N];
int ans_a[N],ans_b[N];
struct node{
	int x,type;	
	node(int x,int type):x(x),type(type){}
};
queue <node> Q;
int calc(int x,int y)
{
	int k=x-y; if (k<=0) k+=n;
	return k;
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&ta);
	rep(i,1,ta) scanf("%d",&a[i]);
	scanf("%d",&tb);
	rep(i,1,tb) scanf("%d",&b[i]);
	ans_a[1]=-1; ans_b[1]=-1; 
	Q.push(node(1,1)); Q.push(node(1,2));
	while (!Q.empty())
	{
		node u=Q.front(); Q.pop();
		int x=u.x,type=u.type;
		if (type==1 && ans_a[x]==1)
		{
			rep(i,1,tb) 
			{
				int p=calc(x,b[i]);
				time_b[p]++;
				if 	(ans_b[p]==0 && time_b[p]==tb)
				{
					ans_b[p]=-1;
					Q.push(node(p,2));
				}
			} 
		}
		if (type==1 && ans_a[x]==-1)
		{
			rep(i,1,tb) 
			{
				int p=calc(x,b[i]);
				if 	(ans_b[p]==0)
				{
					ans_b[p]=1;
					Q.push(node(p,2));
				}
			} 
		}
		if (type==2 && ans_b[x]==1)
		{
			rep(i,1,ta) 
			{
				int p=calc(x,a[i]);
				time_a[p]++;
				if 	(ans_a[p]==0 && time_a[p]==ta)
				{
					ans_a[p]=-1;
					Q.push(node(p,1));
				}
			} 
		}
		if (type==2 && ans_b[x]==-1)
		{
			rep(i,1,ta) 
			{
				int p=calc(x,a[i]);
				if 	(ans_a[p]==0)
				{
					ans_a[p]=1;
					Q.push(node(p,1));
				}
			} 
		}
	}
	rep(i,2,n)
	{
		if (ans_a[i]==1) printf("Win ");
		if (ans_a[i]==-1) printf("Lose ");
		if (ans_a[i]==0) printf("Loop ");
	}
	printf("\n");
	rep(i,2,n)
	{
		if (ans_b[i]==1) printf("Win ");
		if (ans_b[i]==-1) printf("Lose ");
		if (ans_b[i]==0) printf("Loop ");
	}
	
}


//nonamefour0210
#include<bits/stdc++.h>
using namespace std;
const int N=7000;

int n;
vector<int>A;
vector<int>B;
int sa[N+10];///1=win,-1=lose,0=loop
int sb[N+10];
int dega[N+10];
int degb[N+10];
vector<int>p,q;
int lp=0,lq=0;

string func(int i){
    if(i==1)return "Win";
    else if(i==-1)return "Lose";
    else return "Loop";
}

int main(){
    scanf("%d",&n);
    int a;
    for(scanf("%d",&a);a>0;a--){
        int tmp;
        scanf("%d",&tmp);
        A.push_back(tmp);
    }
    for(scanf("%d",&a);a>0;a--){
        int tmp;
        scanf("%d",&tmp);
        B.push_back(tmp);
    }
    for(int i=1;i<=n-1;i++){dega[i]=A.size();degb[i]=B.size();}

    sa[0]=-1;
    q.push_back(0);
    sb[0]=-1;
    p.push_back(0);
    while(lq<q.size()){
        for(int i=0;i<B.size();i++){
            int tmp=(q[lq]-B[i]+n)%n;
            if(sb[tmp]==0){
                sb[tmp]=1;
                for(int j=0;j<A.size();j++)dega[(tmp-A[j]+n)%n]--;
            }
        }
        for(int i=1;i<n;i++)if(sa[i]==0&&dega[i]==0){
            sa[i]=-1;
            q.push_back(i);
            break;
        }
        lq++;
    }
    while(lp<p.size()){
        for(int i=0;i<A.size();i++){
            int tmp=(p[lp]-A[i]+n)%n;
            if(sa[tmp]==0){
                sa[tmp]=1;
                for(int j=0;j<B.size();j++)degb[(tmp-B[j]+n)%n]--;
            }
        }
        for(int i=1;i<n;i++)if(sb[i]==0&&degb[i]==0){
            sb[i]=-1;
            p.push_back(i);
            break;
        }
        lp++;
    }

    for(int i=1;i<n;i++)printf("%s%c",func(sa[i]).c_str(),i==n-1?'\n':' ');
    for(int i=1;i<n;i++)printf("%s%c",func(sb[i]).c_str(),i==n-1?'\n':' ');
}