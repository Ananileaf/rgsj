#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a>b?b:a)
#define INF 0x3f3f3f3f
#define sz() size()
#define pb push_back
#define ph push
#define mem(x, y) memset(x, y, sizeof(x));
#define mem0(x) mem(x,0)
#define mem1(x) mem(x,-1)
#define memINF(x) mem(x,INF)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=a;i>(b);--i)
#define setI(x) freopen(x".txt","r",stdin);
#define setO(x) freopen(x".txt","w",stdout);
#define setIO(x) freopen("xx.in","r",stdin);freopen("xx.out","w",stdout);
using namespace std;
typedef __int64 ll;

int const Max_N = 1e6+5;
int n;
int a[10][10]; 
int belong[10][10];
void init()
{
	int x,y,t;
	rep(i,1,10) rep(j,1,10)
	{
		x = (i-1)/3;
		y = (j-1)/3;
		t = x*3 + y;
		belong[i][j] = t;
	}
}
map<string,int>mp;
bool check()
{
	bool col[10][10] = {false};
	bool row[10][10] = {false};
	bool vis[10][10] = {false};
	string s = "";
	rep(i,1,10) rep(j,1,10)
	{
		int num = a[i][j];
		s += (char)(num+'0');
		int t = belong[i][j];
		if(vis[t][num]||col[i][num]||row[j][num]) return false;
		vis[t][num] = col[i][num] = row[j][num] = true;
	}
	if(mp[s]) return false;
	mp[s]++;
	return true;
}
int main()
{
	#ifdef Anani_leaf
	 
	#endif
	init();
 	setI("sudoku");
 	setO("check"); 
	int cas = 0;
	bool f = true;
	while(cin >> a[1][1])
	{
		rep(i,1,10) 
		{
			if(i==1) rep(j,2,10) cin >> a[i][j];
			else rep(j,1,10) cin >> a[i][j];
		}
		
		if(!check())
		{
			cout << "cas : " << ++cas << ' ' << "Error!" << endl;
			rep(i,1,10)  {
			rep(j,1,10) cout << a[i][j] << ' ';cout << endl;} 
			f = false;
		}
	}
	cout << "No problem" << endl;
	return 0;
}
	//freopen("in.txt","r",stdin);
//std::ios::sync_with_stdio(false);
/*
4 6 2 8 3 1 7 9 5
1 2 3 4 5 6 8 7 9
2 1 4 3 6 5 9 8 7
3 4 1 2 7 9 5 6 8
5 3 6 9 8 7 4 2 1
7 8 9 1 2 4 3 5 6
6 7 8 5 9 2 1 3 4
9 5 7 6 1 8 2 4 3
8 9 5 7 4 3 6 1 2

*/


